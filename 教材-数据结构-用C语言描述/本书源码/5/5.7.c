int Length(GList L)
{ 
	int n=0;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* 空表长度为0 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表 */
	s=L;
	while(s!=NULL)    /* 统计最上层表的长度 */
  	{ 
  		k++;
		s=s->atom_htp.htp.tp;
	}
	return(k);
}
