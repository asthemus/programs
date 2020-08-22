import java.util.*;
import java.lang.*;
import java.io.*;

class MergeSort{
	
	void merge(int arr[], int start, int end, int mid){
		
		int merged[] = new int[end-start+1];
		int i=start,j=mid+1,k=0;
		while(i<=mid && j<=end){
			if(arr[i]<=arr[j]){
				merged[k] = arr[i];
				k++;i++;
			}
			else{
				merged[k] = arr[j];
				k++;j++;
			}
		}
		while(i<=mid){
			merged[k] = arr[i];
			k++;i++;
		}
		while(j<=end){
			merged[k] = arr[j];
			k++;j++;
		}
		for(i=start;i<=end;i++)
			arr[i] = merged[i-start];
	}
	
	void sort(int arr[], int start, int end){
		
		if(start>=end)
			return;
		int mid = (start+end)/2;
		sort(arr,start,mid);
		sort(arr,mid+1,end);
		merge(arr,start,end,mid);
	}
	
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
			
		MergeSort ob = new MergeSort();
		ob.sort(arr,0,n-1);
		for(int i=0;i<n;i++)
			System.out.println(arr[i]+" ");
	}
}
