/*求广义表的表尾*/
GList Tail(GList L)
{
	if(L==NULL) 
		return(NULL);    /* 空表无表尾 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表*/
	else 
		return(L->atom_htp.htp.tp);
}
