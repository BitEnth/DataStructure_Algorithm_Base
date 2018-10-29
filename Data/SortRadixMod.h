/* Need adjustment, just record, not test*/
#define KEY_NUM 8
#define RADIX 10
#define MAX_SPACE 1000

typedef struct{
	int keys[KEY_NUM];
	char info;
	int next;
}NodeType;

typedef struct{
	int f;
	int e;
}QNode;

typedef QNode Queue[RADIX];

void Distribute(NodeType R[], int i, Queue q)
{
	int j, p;
	for(j = 0;j < RADIX;j++){
		q[j].f = 0;
		q[j].e = 0;
	}
	for(p = R[0].next;p;p = R[p].next){
		/* make keys[i] reflect to [0...RADIX]*/
		j = Ord(R[p].keys[i]);
		if(!q[j].f){
			q[j].f = p;
			q[j].e = p;
		}
		else{
			R[q[j].e].next = p;
			q[j].e = p;
		}
	}
}

void Collect(NodeType R[], int i, Queue q)
{
	int t, j;
	/* succ is for the next node*/
	for(j = 0;!q[j].f;j = succ(j)){
		R[0].next = q[j].f;
	}
	t = q[j].e;
	while(j < RADIX){
		for(j = succ(j);j < RADIX && !q[j].f;j = succ(j)){
			if(q[j].f){
				R[t].next = q[j].f;
				t = q[j].e;
			}
		}
	}
	R[t].next = 0;
}

void RadixSort(NodeType R[], int n)
{
	int i;
	Queue q;
	for(i = 0;i < n;i++){
		R[i].next = i+1;
	}
	R[n].next = 0;
	for(i = 0;i < KEY_NUM;i++){
		Distribute(R, i, q);
		Collect(R, i, q);
	}
}
