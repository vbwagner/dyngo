#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

/* 
 * This is small helper to send HUP signal to pid listed in the file
 * Intended to be installed suid root
 * It sends signal with rights of owner of the pidfile.
 */

int main(int argc,char *argv[]) 
{
	FILE *f;
	int pid,count;
	struct stat statbuf;
	if (argc!=2) 
		{
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		fprintf(stderr,"\nThis is small suid helper which sends HUP signal\n");
		fprintf(stderr,"To the process which PID is listed in given file\n");
		exit(1);
		}
	 f=fopen(argv[1],"r");
	 if (!f) 
	 {
		perror(argv[1]);
		exit(1);
	 }
	 if (fstat(fileno(f),&statbuf)!=0) {
	 	perror(argv[1]);
	 }	
	 if (statbuf.st_uid !=0) {
	 	setuid(statbuf.st_uid);
	 }		
	 count=fscanf(f,"%d",&pid);
	 if (count!=1) 
	 {
	 	fprintf(stderr,"Cannot parse pid from %s\n",argv[1]);
		exit(1);
	 }
	 fclose(f);
	 if (kill(pid,SIGHUP)!=0) 
	 {
	 	perror("kill");
	    exit(1);
	 }
	 exit(0);
}
