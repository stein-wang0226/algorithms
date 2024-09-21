void MergeList(LinkList &La,LinkList &Lb){
     //合并两个递增的有序链表，合并后变成递减的有序链表
	pa=La->next,*pb=Lb->next;
	  node *tmp ;// 	
      La->next=NULL; // 置空存放新链表
      while(pa&&pb){
      	if(pa->data<=pb->data){
          	//头插法插pa 在La->q之间
      		tmp=pa->next;//暂存
      		//头插
      		pa->next=La->next;
      		La->next=pa;
      		pa=tmp;//后移
      	}else{
      		tmp=pb->next;
      		pb->next=La->next;
      		La->next=pb;
      		pb=tmp; 
      	}     
      }
	  if(pa){ // pa有剩余
	  	pb=pa;   // 给pb
	  } 
	  while(pb!=NULL){//pb有剩余
	  	q=pb->next;
	  	pb->next=La->next;
	  	pb=q;
	  }
	  free(Lb);
	}