#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int8_t write_buf[1024];
int8_t read_buf[1024];
int main(void)
{
        int fd,opt;
	printf("\t\t\t\t*******************************************\n\n");
        printf("\t\t\t\t*********** OS MINIPROJECT ****************\n\n");
        printf(“\t\t\t\tOpening the Driver...Done!\n”);
        fd = open("/dev/etx_device", O_RDWR);   
	if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
 

                printf("\t\t\t\t*****Please Enter your choice******\n\n");
                printf(" \t\t\t\t 1. Write\t\t\n");
                printf(" \t\t\t\t 2. Read \t\t\n");
                printf(" \t\t\t\t 3. Exit \t\t\n");
                printf("\t\t\t\t************************************\n\n");
         while(1) {
		scanf(" %c", &opt);
                printf("Your Choice = %d\n", opt);
                
                switch(opt) {
                        case 1:
                                printf("Enter the string to write into driver :");
                                scanf("  %s", write_buf);
                                printf("Data Writing ...\n");
                                write(fd, write_buf, strlen(write_buf)+1);
                                printf("Done!\n");
				printf("Select your choice from the above options\t:");
                                break;
                        case 2:
                                printf("Data Reading ...");
                                read(fd, read_buf, 1024);
                                printf("Data = %s\n\n", write_buf);
				printf("Done!\n\n");
				printf("Select your choice from the above options\t:");
                                break;
                        case 3:
                                close(fd);
                                exit(1);
                                break;
                        default:
                                printf("Enter Valid option = %d\n",option);
                                break;
                }
        }
        close(fd);
}
 
