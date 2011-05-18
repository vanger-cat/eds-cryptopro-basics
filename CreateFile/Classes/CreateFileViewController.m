//
//  CreateFileViewController.m
//  CreateFile
//
//  Created by Кондакова Татьяна Андреевна on 03.12.10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "CreateFileViewController.h"
#import "SignFile.h"
#import <sys/types.h>
#import <dirent.h>
#import <sys/stat.h>

@implementation CreateFileViewController

#pragma mark -
#pragma mark Memory management

- (void)dealloc {
	
	[super dealloc];
}


#pragma mark -
#pragma mark Views lifecycle

-(IBAction)startCreatingFile:(id)sender {
	[self createTestFile];
}


-(IBAction)startReadingFile:(id)sender {
	[self readTestFile];
}

-(IBAction)startPane:(id)sender{
	[self launchPane];
}

-(void) launchPane
{
	CPROPane = [[PaneViewController alloc] init];
	UINavigationController * cont = [[UINavigationController alloc] initWithRootViewController:CPROPane];
	[cont setModalPresentationStyle:UIModalPresentationFullScreen];
	[self presentModalViewController:cont animated:YES];
	[cont release];
}

void lslr(const char * path)
{
	struct dirent * d;
	
	DIR * dp = opendir(path);
	if (dp == NULL)
		return;
	while((d=readdir(dp)) != NULL)
	{
		time_t t;
		char buf[PATH_MAX];
		struct stat st;
		sprintf(buf,"%s/%s",path,d->d_name);
		stat(buf,&st);
		t=st.st_mtimespec.tv_sec;
		printf("%s",ctime(&t));
		switch( st.st_mode & S_IFMT)
		{
			case S_IFIFO: printf("p");break;
			case S_IFCHR: printf("b");break;
			case S_IFDIR: printf("d");break;
			case S_IFLNK: printf("l");break;
			case S_IFSOCK: printf("@");break;
			case S_IFREG: printf("-");break;
			case S_IFWHT: printf("w");break;
			default: printf("?");break;
		}
		
		
		printf("%c%c%c%c%c%c%c%c%c%c%c%c",
			   (st.st_mode&S_ISVTX)?'t':'-',
			   (st.st_mode&S_ISUID)?'s':'-',
			   (st.st_mode&S_IRUSR)?'r':'-',
			   (st.st_mode&S_IWUSR)?'w':'-',
			   (st.st_mode&S_IXUSR)?'x':'-',
			   (st.st_mode&S_ISGID)?'s':'-',
			   (st.st_mode&S_IRGRP)?'r':'-',
			   (st.st_mode&S_IWGRP)?'w':'-',
			   (st.st_mode&S_IXGRP)?'x':'-',
			   (st.st_mode&S_IROTH)?'r':'-',
			   (st.st_mode&S_IWOTH)?'w':'-',
			   (st.st_mode&S_IXOTH)?'x':'-');
		printf(" %s\n",buf);
		if (d->d_type & DT_DIR && strcmp(d->d_name,".") && strcmp(d->d_name,".."))
		{
			lslr(buf);
		}
	}
	closedir(dp);
}


// Display dialog box
- (void) createTestFile
{
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
	NSString *d1 = [ NSString stringWithFormat:@"%@/..", documentsDirectory ];
	lslr([d1 fileSystemRepresentation]);
    //make a file name to write the data to using the documents directory:
    NSString *fileName = [NSString stringWithFormat:@"%@/textfile.txt", 
						  documentsDirectory];
    NSString *content = @"Test123";
    //save content to the documents directory
    [content writeToFile:fileName 
              atomically:NO
                encoding:NSStringEncodingConversionAllowLossy 
                   error:nil];
	const char* fileNameC = [fileName cStringUsingEncoding:[NSString defaultCStringEncoding]];
	char outFileNameC[256];
	strcpy(outFileNameC, fileNameC);
	strcat(outFileNameC, ".sig");
	DWORD ret = do_low_sign(fileNameC, outFileNameC);
	if(!ret){
		UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Sign" message:@"everything is ok." delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] autorelease];
		[alert show];
	}
	else{
		UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Sign" message:@"sign failed." delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] autorelease];
		[alert show];
	}
}

- (void) readTestFile

{
	
	NSArray *paths = NSSearchPathForDirectoriesInDomains
	(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
	
    //make a file name to write the data to using the documents directory:
    NSString *fileName = [NSString stringWithFormat:@"%@/textfile.txt", 
						  documentsDirectory];
    //save content to the documents directory
	const char* fileNameC = [fileName cStringUsingEncoding:[NSString defaultCStringEncoding]];
	char sigFileNameC[256];
	char outFileNameC[256];
	strcpy(outFileNameC, fileNameC);
	strcat(outFileNameC, ".out");
	strcpy(sigFileNameC, fileNameC);
	strcat(sigFileNameC, ".sig");
	DWORD ret = do_low_verify(sigFileNameC, outFileNameC);
	
	if(!ret){
		UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Verify" message:@"signature was verified" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] autorelease];
		[alert show];
	}
	else{
		UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Verify" message:@"signature was not verified" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] autorelease];
		[alert show];
	}
	
	//    NSString *content_read = [[NSString alloc] initWithContentsOfFile:fileName
	//														 usedEncoding:nil
	//																error:nil];
	//use simple alert from my library (see previous post for details)
	//	UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"File content" message:content_read delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] autorelease];
	//    [alert show];
	
}

@end

