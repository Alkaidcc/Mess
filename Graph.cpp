//宽度(广度)优先遍历
void bfs(Node* node)
{
	if(node==NULL)
	{
		return;
	}	
	deque<Node*>	deq;
	set<Node*> set;
	
	deq.push_back(node);
	set.insert(node);
	while(deq.size()!=0)
	{	
		Node* cur=deq.front();	//保存deq队列首元
		deq.pop_front();//出队列打印
		cout<<cur->value<<" ";
		for(Node* next:cur->next)
		{
			if(set.find(next)==set.end())
			{				
				deq.push_back(next);
				set.insert(next);
			}
		}	
	}
	cout<<endl;
}