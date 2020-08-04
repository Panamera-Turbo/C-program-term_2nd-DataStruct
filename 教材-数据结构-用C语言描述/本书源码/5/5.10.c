int CopyGList(GList S, GList *T)
{ 
	if(S==NULL) 
	{ 
		*T=NULL; 
		return(OK); 
	}    /* 复制空表 */
	*T=(GLNode *)malloc(sizeof(GLNode));
	if(*T==NULL) 
		return(ERROR);
	(*T)->tag=S->tag;
	if(S->tag==ATOM) 
		(*T)->atom=S->atom;    /* 复制单个原子 */
	else
	{
		CopyGList(S->atom_htp.htp.hp, &((*T)->atom_htp.htp.hp));    /* 复制表头 */
		CopyGList(S->atom_htp.htp.tp, &((*T)->atom_htp.htp.tp));    /* 复制表尾 */
  	}
	return(OK);
}
