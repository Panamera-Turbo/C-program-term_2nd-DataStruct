/*求广义表的表头*/
GList Head(GList L)
{
	if(L==NULL) 
		return(NULL);    /* 空表无表头 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表 */
	else 
		return(L->atom_htp.htp.hp);
}

