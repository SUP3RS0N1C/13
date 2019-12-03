#define MAX_NAME 30 //매크로  

struct keytab{ //구조체 틀  
	int nums; //몇번나오는지 카운트
	char name[MAX_NAME]; //가장긴키워드의 길이  
};

struct keytab keywrds[13/*원래는 매크로로 들어가야함*/] ={
	{0, "int"},
	{0, "float"},
	{0, "return"},
	{0, "if"},
	{0, "for"},
	{0, "while"},
	{0, "goto"},
	{0, "switch"},
	{0, "case"},
	{0, "void"},
	{0, "default"},
	{0, "char"},
	{0, "do"}
};

void count_word(char *word){
	int i;
	//repeat each keywords
	for (i=0;1<13;i++)
	{	//if word and i'th keyword is same
		if(strncmp(word, keywrds[i].name, strlen(keywrds[i].name)/*keywrds문자열의 길이*/)==0/*n개까지 비교*/){
			//nums++;
			keywrds[i].nums++;
		}
	}
} 

void print_word()//키워드의 등장횟수를 프린트
{
	int i;
	//i번쨰 키워드에 대해서
	for(i=0;i<13;i++)
	{
		//printf(키워드이름:빈도수);
		printf("%s : %i", keywrds[i].name, keywrds[i].nums);
	}
}
