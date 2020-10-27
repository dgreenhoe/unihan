/*============================================================================
 * Daniel J. Greenhoe
 * unicode variants text file to TECkit map file
 *============================================================================*/


/*=====================================
 * header files
 *=====================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*=====================================
 * internal prototypes
 *=====================================*/
int var2map(char *namein, char *nameout);

/*-------------------------------------
 * main
 *-------------------------------------*/
int main(int argc, char *argv[]){
  int rval;

  srand((unsigned)time(NULL));

  if(argc==3){
    rval=var2map(argv[1],argv[2]);
    }
  else{
    fprintf(stderr,"Usage:\n");
    fprintf(stderr,"  %s <input Variants file> <output TECkit map file>\n",argv[0]);
    fprintf(stderr,"For input file, see for example \"Unihan_Variants.txt\" in\n  \"http://www.unicode.org/Public/6.1.0/ucd/ Unihan-6.1.0d1.zip\"\n");
    fprintf(stderr,"For example TECkit mapping files, see\n  \"http://scripts.sil.org/cms/scripts/page.php?item_id=MappingFiles\"\n");
    rval=-1;
    }

  if(rval)fprintf(stderr,"Error: rval=%d\n",rval);
  return rval;
  }

/*----------------------------------------------------------------------------
 * Variants to TECkit mapping file
 *   Input:  filename of Unihan_Variants.txt file (ASCII encoded)
 *           see for example "Unihan_Variants.txt" in http://www.unicode.org/Public/6.1.0/ucd/ Unihan-6.1.0d1.zip
 *   Output: filename of TECkit mapping file
 *           For examples see http://scripts.sil.org/cms/scripts/page.php?item_id=MappingFiles
 *----------------------------------------------------------------------------*/
int var2map(char *namein, char *nameout){
  #define MAXLINE 1024
  long i;
  int j;
  char *fval,*sval;
  FILE *fpin,*fpout;
  char buf[MAXLINE];
 
    fpin =fopen(namein,"r");
    fpout=fopen(nameout,"w");
    if(fpin==NULL){
      fprintf(stderr,"Unable to open file %s\n",namein);
      return -1;
      }
    if(fpout==NULL){
      fprintf(stderr,"Unable to open file %s\n",nameout);
      return -1;
      }
  fprintf(fpout,";==============================================================================\n");
  fprintf(fpout,"; Variants to TECkit mapping file\n");
  fprintf(fpout,"; Input file name: %s\n",namein);
  fprintf(fpout,"; Output file name: %s\n",namein);
  fprintf(fpout,"; Daniel J. Greenhoe \n");
  fprintf(fpout,";==============================================================================\n");
  fprintf(fpout,";\n");
  fprintf(fpout,"LHSName               \"zh-traditional\"\n");
  fprintf(fpout,"RHSName               \"zh-simplified\"\n");
  fprintf(fpout,"LHSDescription        \"Unicode 6.1.0 traditional Chinese characters\"\n");
  fprintf(fpout,"RHSDescription        \"Unicode 6.1.0 simplified  Chinese characters\"\n");
  fprintf(fpout,"Version               \"0\"\n");
  fprintf(fpout,"Contact               \"mailto:dgreenhoe@gmail.com\"\n");
  fprintf(fpout,"RegistrationAuthority \"Abstract Space Publishing\"\n");
  fprintf(fpout,"RegistrationName      \"zh-t2s-610\"\n");
  fprintf(fpout,"pass(Unicode)\n");  /* allow unicode input and output */

  for(i=1,fval=" ";fval!=NULL;i++){
    fval=fgets(buf,MAXLINE,fpin);
    sval=strchr(buf,'\n');
    if(sval!=NULL) *sval = '\0'; //*sval=NULL;    /* remove newline character from string */
    sval=strchr(buf,'#');
    if(sval!=NULL) *sval = '\0'; //*sval=NULL;    /* delete comments */
    sval=strstr(buf,"kSimplifiedVariant");
    if(sval!=NULL){
      *sval = '>'; /* replace 'k' with mapping operator */
      for(j=1; j<=17; j++) sval[j]=' '; /* replace "SimplifiedVariant" with spaces */
      fprintf(fpout,"%s ; %6ld\n",buf,i);
      }
    }
  fclose(fpin);
  fclose(fpout);
  return 0;
  }

