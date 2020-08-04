int CountAtom(GList L)
{ /*求广义表L中原子结点数目，并返回原子结点数目值*/
	int n;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* 空表中没有原子 */
	if(L->tag==ATOM) 
		return(1);    /* L指向单个原子 */
	s=L; 
	n=0;
	while(s!=NULL)    /* 求每个子表的原子数目之和 */
  	{ 
  		n=n+CountAtom(s->atom_htp.htp.hp);
		s=s->atom_htp.htp.tp;
	}
	return(n);
}
