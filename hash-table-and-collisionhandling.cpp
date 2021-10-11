#include <iostream>
using namespace std;
#define SIZE 10
#define PRIME 7
void Print(int vec[], int n){
    cout<< flush;
    for (int i=0; i<n; i++){
        cout <<"key="<<i<<",value="<<vec[i]<<endl << flush;
        if (i < n-1){
            cout << "" << flush;
        }
    }
    cout << endl;
}
int Hash(int key){
    return key % SIZE;
}
int LinearProbe(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(index+i) % SIZE] != 0){
        i++;
    }
    return (index + i) % SIZE;
}
int QuadProbe(int H[],int key){
	int index=Hash(key);
	int i=0;
	while(H[(index+(i*i))%SIZE] != 0){
		i++;
	}
	return(index+(i*i))%SIZE;
}
int PrimeHash(int key){
    return PRIME - (key % PRIME);
}

int DoubHash(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(Hash(index) + i * PrimeHash(index)) % SIZE] != 0){
        i++;
    }
    return (index + i * PrimeHash(index)) % SIZE;
}

void Insert_DoubHash(int H[], int key){
    int index = Hash(key);

    if (H[index] != 0){
        index = DoubHash(H, key);
    }
    H[index] = key;
}
void Insert_L(int H[], int key){
    int index = Hash(key);
    if (H[index] != 0){
        index = LinearProbe(H, key);
    }
    H[index] = key;
}
void Insert_Q(int H[], int key){
    int index = Hash(key);
    if (H[index] != 0){
        index = QuadProbe(H, key);
    }
    H[index] = key;
}
int main() {
    int n,ch;
    cout<<"Enter the size: ";
    cin>>n;
    int A[n]={0};
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int HT[10] = {0};
    do
    {
        cout<<"1.Linear probing 2.Quadratic Probing 3.Double hashing 4.Quit\n";
        cin>>ch;
        switch(ch){
        	case 1:
        		cout<<"Values and keys after linear probing in order"<<endl;
                for (int i=0; i<n; i++){
                    Insert_L(HT, A[i]);
                    
                        }
                Print(HT,SIZE);      
                break;
        	case 2:
        		cout<<"Values and keys after Quadratic probing in order "<<endl;
                for (int i=0; i<n; i++){
                    Insert_Q(HT, A[i]);               
                        }
				Print(HT,SIZE); 		 
				break; 
			case 3:
				cout<<"Values and keys after Double hashing in order "<<endl;
				for(int i=0;i<n;i++){
					Insert_DoubHash(HT,A[i]);
				}
				Print(HT,SIZE); 
			    break;
			case 4:
			    break;		             
}
}while(ch<5);
    return 0;
}
