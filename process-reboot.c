#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
/* this program check for a process if running or if it got executed the program send a force reboot or a force shutdown signal to the system */
int main()
{
    char *Process[] = {"Mozilla", "Firefox"};
    for(;;){
    system("ps aux > file.txt"); // save the process list in a text file in linux
    // system("tasklist > file.txt"); // save the process list in a text file in windows
    FILE *fp=fopen("file.txt","r");
    char tmp[256]={0x0};
    while(fp!=NULL && fgets(tmp, sizeof(tmp), fp)!=NULL)
    {
        if (strstr(tmp, Process[0])){
            printf("%s", tmp);
            system("rm file.txt");
            system("reboot -f");
            // system("poweroff -f"); // force shutdown for linux
            // system("shutdown -s -f"); // force shutdown for windows
            // system("Shutdown -r -f"); // force reboot for windows
            exit(0);
            }
                else if (strstr(tmp, Process[1])){
            printf("%s", tmp);
            system("rm file.txt");
            system("reboot -f");
            // system("poweroff -f"); // force shutdown for linux
            // system("shutdown -s -f"); // force shutdown for windows
            // system("Shutdown -r -f"); // force reboot for windows
            exit(0);
            }
            else {
            system("rm file.txt");
            }
    }
 //   if(fp!=NULL) fclose(fp);
    }
    return 0;
}
