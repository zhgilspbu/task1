#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


struct que{

int id;
que* next;
que* prev;
};

void push(que *&head,int num){

if (!head){
que* temp=new que;
temp->id=num;
temp->next=head;
temp->prev=NULL;
head->prev=temp;
head=temp;}
else{
que* temp=new que;
temp->id=num;
temp->next=NULL;
temp->prev=NULL;
head=temp;
}
}

int front(que *&head){
int ans;
if (head->next==NULL){

    ans=head->id;
    delete head;
    return ans;
}
else{
    que* ptr=head;
    while(ptr->next){
        ptr=ptr->next;
    }
    ans=ptr->id;
    ptr->prev->next=NULL;
    delete(ptr);
    return ans;

}

}


#endif // QUEUE_H_INCLUDED
