#include <stdio.h>
#include <stdlib.h>

//프레임형성  
typedef struct linknode{
	int data;
	
	void* next;//구조체를 가리키는 포인터, 구조체안에 구조체를 넣을 수 없으므로   
} ln_t;

static ln_t *list;//다른파일에서 직접 접근할수없도록 조치 

int create_node(int value)//그떄그때 메모리를 잡는다  
{
	ln_t *ptr;
	ln_t *ptrTrav;
	int cnt;
	
	ptr = (ln_t*/*할당?*/)malloc(sizeof(ln_t));//맬록을통해 메모리를 잡는다
	if(ptr == NULL)//메모리 부족해서 안잡히는 경우 할당을 못받아서 널값이됨  
	{
		//printf("memory error")
		return -1; 
	}//방어코드, 오류생기면 -1반환해서 문제생겼음을 티내기  
	
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(list == NULL)
	{
		list = ptr;
		cnt=0; 
	}
	else
	{
		ptrTrav = list;//추가된 마지막 노드를 가리키도록 해야하므로  
		cnt++;
		while(ptrTrav->next != NULL)//포인터트래블이 가르키는것이 NULL이될때까지 진행  
		{
			ptrTrav = ptrTrav->next; 
			cnt++;
		}
		ptrTrav->next = ptr;
	}
	return cnt;
} 

