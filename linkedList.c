#include <stdio.h>
#include <stdlib.h>

//����������  
typedef struct linknode{
	int data;
	
	void* next;//����ü�� ����Ű�� ������, ����ü�ȿ� ����ü�� ���� �� �����Ƿ�   
} ln_t;

static ln_t *list;//�ٸ����Ͽ��� ���� �����Ҽ������� ��ġ 

int create_node(int value)//�׋��׶� �޸𸮸� ��´�  
{
	ln_t *ptr;
	ln_t *ptrTrav;
	int cnt;
	
	ptr = (ln_t*/*�Ҵ�?*/)malloc(sizeof(ln_t));//�ȷ������� �޸𸮸� ��´�
	if(ptr == NULL)//�޸� �����ؼ� �������� ��� �Ҵ��� ���޾Ƽ� �ΰ��̵�  
	{
		//printf("memory error")
		return -1; 
	}//����ڵ�, ��������� -1��ȯ�ؼ� ������������ Ƽ����  
	
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(list == NULL)
	{
		list = ptr;
		cnt=0; 
	}
	else
	{
		ptrTrav = list;//�߰��� ������ ��带 ����Ű���� �ؾ��ϹǷ�  
		cnt++;
		while(ptrTrav->next != NULL)//������Ʈ������ ����Ű�°��� NULL�̵ɶ����� ����  
		{
			ptrTrav = ptrTrav->next; 
			cnt++;
		}
		ptrTrav->next = ptr;
	}
	return cnt;
} 

