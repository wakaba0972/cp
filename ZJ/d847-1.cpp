/*
  此程式是配合學校作業要求寫ㄉ
  所以排序啥的都自己刻
  這邊是用分治法來解
  以後可能會寫線段樹 or BIT版本ㄉ
*/

#include<bits/stdc++.h>
using namespace std;

// 建立heap
// 每次插到當前heap最後一個node
// 如果比parent大, 則swap
template <class T>
void build_heap(int size, T arr[]){
	for(int i=0; i<size; i++){
		int now = i;
		while(now > 0){	
			int parent = (now-1)/2;
			if(arr[parent] < arr[now]){
				swap(arr[now], arr[parent]);
				now = parent;
			}
			else{
				break;
			}
		}
	}
}

// 從root出發, 每次跟左右子節點中較大的對調
// 直到當前子樹滿足max heap, 或走到leaf
template <class T>
void readjust(int size, T arr[]){
	int now = 0;
	while(true){
		int left = 2*now+1;
		int right = 2*now+2;
		
		// current node is a leaf
		if(left >= size){
			break;
		}
		// current node have a only child (left)
		else if(left < size && right >= size){
			if(arr[now] < arr[left]) {
				swap(arr[left], arr[now]);
			}
			break;
		}
		// current node have 2 childs
		else{
			if(arr[now] < arr[left] || arr[now] < arr[right]){
				int larger_node = ((arr[left] < arr[right])? right: left);
				swap(arr[larger_node], arr[now]);
				now = larger_node;
			}
			else{
				break;
			}
		}
	}
}

// 堆積排序(升序)
template <class T>
void heap_sort(int origin_size, T arr[]){
	int size = origin_size;
	build_heap(origin_size, arr);
	
	while(size > 0){
		// Exchange, 將最後一個元素和root對調
		swap(arr[0], arr[size-1]);
		size--;
		// 重新調整heap, 使滿足max heap性質
		readjust(size, arr);
	}
	
	//for(int i=0; i<origin_size; i++) cout << arr[i].x << ' ' << arr[i].y << endl;
}

// 自定義point
struct point{
	int x, y;
	int id;
	
    // 以x小到大排序, x相同則以y大到小排序
    // 當x相同, 兩點是incomparable的, 故y大的排前面可以避免誤判

	// 考慮(1, 1), (1, 2)兩點
	// 若(1, 1)在左區間, (1, 2)在右區間, 根據split()內的邏輯, (1, 2)會被判定dominate (1, 1)
	// 因為split()是左區間的點只要y值比右區間的點小, 就會被判定為dominate(沒有檢查x值)
	// 所以要排序成(1, 2), (1, 1), 因為(1, 2)的y值比(1, 1)大，就不會被誤判
	bool operator<(const point &other) const{
		if(x == other.x) return y > other.y;
		else return x < other.x;
	}
};

void merge(int l, int r, int mid, int size, point points[], int ranks[]){
	//cout << "------------------------------" << endl;
	//cout << "split " << l << ' ' << mid << ' ' << r << endl; 
	
	int idx = 0, cnt = 0;
	int l_ptr = l, r_ptr = mid+1;
	point merged[r-l+1];
	
	// sort tmp_arr
	while(l_ptr <= mid && r_ptr <= r){
		if(points[l_ptr].y < points[r_ptr].y){
			merged[idx++] = points[l_ptr++];
			cnt++;
		}
		else{
			merged[idx++] = points[r_ptr];
			ranks[points[r_ptr++].id] += cnt;
		}
	}
	
	while(l_ptr <= mid){
		merged[idx++] = points[l_ptr++];
	}
	
	while(r_ptr <= r){
		merged[idx++] = points[r_ptr];
		ranks[points[r_ptr++].id] += cnt;
	}
	
	for(int i=l; i<=r; i++){
		points[i] = merged[i-l];
	}

	//cout << "------------------------------" << endl;
}

void split(int l, int r, int size, point points[], int ranks[]){
	if(l >= r) return;
	
	int mid = (l + r) / 2;
	
	split(l, mid, size, points, ranks);
	split(mid+1, r, size, points, ranks);
	merge(l, r, mid, size, points, ranks);
}

void two_d_rank(int size, point points[]){
	int ranks[size];
	memset(ranks, 0, sizeof(ranks));

	split(0, size-1, size, points, ranks);
	
	for(int i=0; i<size; i++) cout << ranks[i] << endl;
}

int main(){
	int size;
	while(cin >> size){
		// read file
		int x, y;
		int idx = 0;
		point points[10005];
		
		for(int i=0; i<size; i++){
			cin >> x >> y;
			points[i] = {x, y, idx++};
		}
		
		heap_sort(size, points);
		two_d_rank(size, points);
	}
}