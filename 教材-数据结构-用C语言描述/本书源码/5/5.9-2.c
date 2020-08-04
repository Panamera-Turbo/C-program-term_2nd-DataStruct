int CountAtom(GList L)
{ 
	int n1, n2;
	if(L==NULL) 
		return(0);    /* 空表中没有原子 */
	if(L->tag==ATOM) 
		return(1);    /* L指向单个原子 */
	n1=CountAtom(L->atom_htp.htp.hp);    /* 求表头中的原子数目 */
	n2=CountAtom(L->atom_htp.htp.tp);    /* 求表尾中的原子数目 */
	return(n1+n2);
}
