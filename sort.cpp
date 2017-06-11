#include <cstdlib>
#include <iostream>
#include <iostream>
using namespace std;

int ins_count=0;
int merge_count=0;
int quick_count=0;

void insertion_sort(int A[],int num_of_items);

void merge_sort(int B[], int low, int high,int num_of_items);
void merge(int B[],int low,int mid, int high,int num_of_items);

void quick_sort(int C[],int low,int high);
void partition ( int C[], int low, int high, int &i, int &j );

void swap(int* a, int* b);

int main()
{
        int num_of_items;
        int seed;
        char answer1;
        char answer2;

        cout<<"Enter the number of values to generate and sort, between 1 and 5000: ";
        cin>>num_of_items;
        cout<<endl;

        cout<<"Enter an integer seed value: ";
        cin>>seed;
        cout<<endl;

        int merge[num_of_items];
        int insertion[num_of_items];
        int quick[num_of_items];

        srand(seed);
        for(int i=0;i<num_of_items;i++)
        {
                insertion[i] = (rand()%5000)+1;
                merge[i]     = insertion[i];
                quick[i]     = insertion[i];
        }

        cout<<"Print the values?(y/n): ";
        cin>>answer1;
        cout<<endl;


        if(answer1=='y')
        {
                cout<<"What sorting algorithm?(i for insertion sort || m for merge sort || q for quick sort: ";
                cin>>answer2;
                cout<<endl;

                cout<<"Unsorted: "<<endl;
                for(int i=0;i<num_of_items;i++)
                        cout<<quick[i]<<endl;
                cout<<"----------------------------------------"<<endl<<endl;
                cout<<"Sorted: "<<endl;
                insertion_sort(insertion,num_of_items);
                merge_sort(merge,0,num_of_items-1,num_of_items);
                quick_sort(quick,0,num_of_items-1);
                if(answer2=='i')
                {
                        for(int i=0;i<num_of_items;i++)
                                cout<<insertion[i]<<endl;
                }
                else if(answer2=='m')
                {
                        for(int i=0;i<num_of_items;i++)
                                cout<<merge[i]<<endl;
                }
                else//quick sort;
                {
                        for(int i=0;i<num_of_items;i++)
                                cout<<quick[i]<<endl;
                }

        }
        else
        {
                insertion_sort(insertion,num_of_items);
                merge_sort(merge,0,num_of_items-1,num_of_items);
                quick_sort(quick,0,num_of_items-1);
        }
cout<<"Insertion sort count: "<<ins_count<<endl<<endl;
cout<<"Merge sort count: "<<merge_count<<endl<<endl;
cout<<"Quick sort count: "<<quick_count<<endl<<endl;
}



void insertion_sort (int A[], int num_of_items )
{
        int j;
        for (int i=1; i<num_of_items; ++i)
        {

                j = i;
                while (j>0 && A[j] < A[j-1])
                {
                        ins_count++;
                        swap(A[j],A[j-1]);
                        --j;
                }
        }
}

void merge_sort(int B[], int low, int high,int num_of_items)
{
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                merge_sort(B,low,mid,num_of_items);
                merge_sort(B,mid+1,high,num_of_items);
                merge(B,low,mid,high,num_of_items);
        }
}

void merge(int B[],int low, int mid,int high,int num_of_items)
{
        int D[num_of_items];
        int i1,i2,index;
        for(int i=low;i<=high;++i)
        {
        merge_count++;
        D[i]=B[i];
        }

        i1=low,
        i2=mid+1;
        index=low;

        while(i1<=mid && i2<=high)
        {
                merge_count++;
                if(D[i1]<D[i2])
                        {B[index++]=D[i1++];}
                else
                        {B[index++]=D[i2++];}
        }

        while(i1<=mid)
        {
                merge_count++;
                B[index++]=D[i1++];
        }

        while(i2<=high)
        {
                merge_count++;
                B[index++]=D[i2++];
        }
}

void quick_sort (int C[], int low, int high )
{
        int i, j;
        if ( low < high )
        {
                partition ( C, low, high, i, j );
                quick_sort ( C, low, i );
                quick_sort ( C, j, high );
        }
}

void partition ( int C[], int low, int high, int &i, int &j )
{
        int pivot = C[low];
        int lastS1 = low - 1;
        int firstU = low;
        int firstS3 = high + 1;

        while ( firstU < firstS3 )
        {
                quick_count++;
                if ( C[firstU] < pivot )        // S1
                {
                        ++lastS1;
                        swap ( C[firstU],C[lastS1] );
                        ++firstU;
                }
                else if ( C[firstU] == pivot )  // S2
                        {++firstU;}
                else  // C[firstU] > pivot      // S3
                {
                        --firstS3;
                        swap ( C[firstU], C[firstS3] );
                }
        }
        i = lastS1;
        j = firstS3;
}

void swap(int* a, int* b)
{
        int t = *a;
        *a = *b;
        *b = t;
}
