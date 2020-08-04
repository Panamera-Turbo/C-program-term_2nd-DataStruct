int Depth(GList L)
{ 
	int d, max;
	GLNode *s;
	if(L==NULL) 
		return(1);    /* 空表深度为1 */
	if(L->tag==ATOM) 
		return(0);    /* 原子深度为0 */
	s=L;
	while(s!=NULL)    /* 求每个子表的深度的最大值 */
	{ 
		d=Depth(s->atom_htp.htp.hp);
		if(d>max) max=d;
    		s=s->atom_htp.htp.tp;
   	}
	return(max+1);    /* 表的深度等于最深子表的深度加1 */
}
