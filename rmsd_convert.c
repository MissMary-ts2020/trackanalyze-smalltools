#include <stdio.h>
int main(int argc,char** argv){
    FILE* csv_origin=fopen(*(argv+1),"r");
    FILE* csv_output=fopen(*(argv+2),"w");
    if(!csv_origin||!csv_output){
        printf("Error!文件不存在!\n");
        return 1;
    }
    fprintf(csv_output,"time,val\n");
    char line[256]="";
    char line_left[128]="";
    char line_right[128]="";
    char temp[128]="";
    char temp1[128]="";
    double num=0;
    double false_num=0.0;
    double true_num=0.0;
    while(fgets(line,sizeof(line),csv_origin)){
        if(3==sscanf(line,"%lf ,[ %lf %lf]",&num,&false_num,&true_num)){
            fprintf(csv_output,"%.1lf,%.10lf\n",num*0.5,true_num);
        }else{
            printf("Error with resding line %s!\n",line);
            fclose(csv_origin),fclose(csv_output);
            return 1;
        }
        
    }
    
    fclose(csv_origin),fclose(csv_output);
    return 0;
}