#include "stdio.h"
#include "stdlib.h"

/*链式存储方式下的模式匹配，每个字符用一结点表示*/

typedef struct Block{
	char   ch;
	struct Block   *next;
}Block;

typedef struct {
	Block   *head;
	Block   *tail;
	int     len;
}BLString;

int StrAssign(BLString *s, char *tval)
/*将字符串常量tval的值赋给块链串s*/
{
	Block *p,*q;
	int len, i=0;

	if (s->head != NULL) {
		/*释放原来存储在S中的结点空间*/
		p = s->head;
		while (p != NULL) {
			q = p->next;
			free(p);
			p = q;
		}

		s->head = s->tail = NULL;
	}

	/*计算字符串长度*/
	while (tval[i] != '\0') i++;

	len = i;s->len = len;

	if (len > 0) {
		p = (Block *)malloc(sizeof(Block));
		if (p == NULL) return 1;
		s->head = s->tail = q = p;
		i=0;

		while (i < len) {
			p = (Block *)malloc(sizeof(Block));
			if (p == NULL) return 1;
			q->next = p;q = p;

			//printf("\nCopying %c",tval[i]);
			p->ch = tval[i++];
		}
	}

	q->next = NULL;s->tail = q;

	return 0;
}

int StrDelete(BLString *s, int pos, int len)
{
	/*在串s中删除从下标pos起len个字符 */
	int i,j;
	Block *p,*q,*r;

	if (pos<0 || pos>(s->len - len)) return 1;

	i = 0;
	p = s->head;
	while(i<pos){
		p = p->next;
		i++;
	}

	q = p;

	j = 0;
	p = p->next;
	while (j<len) {
		r = p->next;
		//printf("\ndeleting %c",p->ch);
		free(p);
		p = r;
		j++;
	}

	q->next = p;
	s->len = s->len - len;
	if (q->next == NULL) {
		s->tail = q;
	}

	return 0;
}

Block *StrIndex(BLString *s, BLString *t)
/*求子串t在主串s中第一次出现的位置指针*/
{
	Block *p = NULL;
	Block *q = NULL;
	Block *tmp = NULL;
	int j;

	if (t->len == 0) return NULL;

	p = s->head->next;
	q = t->head->next;
	tmp = p;
	j = 0;
	while(p != NULL && q != NULL)
	{
		if (p->ch == q->ch) {
			p = p->next;
			q = q->next;
		}
		else
		{
			p = tmp->next;
			tmp = p;
			j++;
			q = t->head->next;
		}
	}

	if ( q == NULL) {
		printf("\nFound!=%c in position %d\n",tmp->ch,j);
		return tmp;
	}
	else return NULL;
}

int main()
{
	static BLString s,t;
	char str1[80],str2[80];

	printf("请输入主串s的内容：");
	scanf("%s",str1);
	printf("\n请输入子串t的内容：");
	scanf("%s",str2);

	StrAssign(&s,str1);
	StrAssign(&t,str2);

	Block *pos = StrIndex(&s,&t);
	if (pos == NULL) {
		printf("\nString not found!\n");
	}

	//释放空间
	StrDelete(&s,0,s.len);
	StrDelete(&t,0,t.len);
	return 0;
}