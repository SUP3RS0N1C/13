#define MAX_NAME 30 //��ũ�� 
#define N_KEYS 14

struct keytab{ //����ü Ʋ  
	int nums; //����������� ī��Ʈ
	char name[MAX_NAME]; //�����Ű������ ����  
};

struct keytab keywrds[N_KEYS] ={
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
	{0, "do"},
	{0, "scanf"}
};

void count_word(char *word){
	int i;
	//repeat each keywords
	for (i=0;i<N_KEYS;i++)
	{	//if word and i'th keyword is same
		if(strncmp(word, keywrds[i].name, strlen(keywrds[i].name)/*keywrds���ڿ��� ����*/)==0/*n������ ��*/){
			//nums++;
			keywrds[i].nums++;
		}
	}
} 

void print_word()//Ű������ ����Ƚ���� ����Ʈ
{
	int i;
	//i���� Ű���忡 ���ؼ�
	for(i=0;i<N_KEYS;i++)
	{
		//printf(Ű�����̸�:�󵵼�);
		printf("%s : %i\n", keywrds[i].name, keywrds[i].nums);
	}
}
