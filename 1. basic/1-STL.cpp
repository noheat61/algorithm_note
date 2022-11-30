#include <bits/stdc++.h>
using namespace std;

void stack_example()
{
    // LIFO를 사용할 때
    // vector로 대체
    stack<int> ss;
    int a = 0;

    ss.push(a); //원소 a를 삽입             //O(1)
    ss.top();   //가장 위의 원소 반환       //O(1)
    ss.pop();   // top의 원소를 빼내기      //O(1)
    ss.size();  //원소의 개수 반환         	//O(1)
}

void queue_example()
{
    // FIFO를 사용할 때
    queue<int> qq;
    int a = 0;

    qq.push(a); //원소 a를 삽입             //O(1)
    qq.front(); //가장 앞의 원소 반환   	//O(1)
    qq.back();  //가장 뒤의 원소 반환      	//O(1)
    qq.pop();   // front의 원소를 빼내기    //O(1)
    qq.size();  //원소의 개수 반환    		//O(1)
}

void vector_example()
{
    // 정렬하지 않는 자료구조 중 FIFO를 제외한 대부분(LIFO, 배열 등)
    vector<int> vv;
    int n = 0, a = 0;
    auto it = vv.begin();

    vv.front();       //가장 앞 원소 반환             	//O(1)
    vv.back();        //가장 뒤 원소 반환               //O(1)
    vv.insert(it, a); // it에 원소 a를 삽입  	        //O(N)
    vv.erase(it);     // it가 가리키는 원소 제거        //O(N)
    vv.clear();       //벡터를 완전히 비움            	//O(N)(빠름)
    vv.begin();       //벡터의 시작을 가리키는 it 반환	//O(1)
    vv.end();         //벡터의 끝을 가리키는 it 반환 	//O(1)
    vv.size();        //원소의 개수 반환             	//O(1)
    vv.push_back(a);  //원소 a를 가장 뒤에 삽입         //O(1)
    vv.pop_back();    //가장 뒤 원소를 빼내기          	//O(1)
}

void pq_example()
{
    // 정렬하는 자료구조 중 가장 큰(작은) 원소의 값만 필요할 때
    priority_queue<int> pq;                             // MAX힙(최댓값을 내놓음)
    priority_queue<int, vector<int>, greater<int>> pq2; // MIN힙(최솟값을 내놓음)
    int a = 0;

    pq.push(a); //원소 a를 삽입          	//O(logN)
    pq.top();   //가장 큰(작은) 원소 반환	//O(1)
    pq.pop();   // top의 원소를 빼내기    	//O(logN)
    pq.size();  //원소의 개수 반환       	//O(1)
}

void set_example()
{
    // 정렬하는 자료구조 중 다양한 위치에 대한 참조가 필요할 때
    set<int> ss;
    int a = 0;
    auto it = ss.begin();

    ss.find(a);   //원소 a를 가리키는 it 반환       //O(logN)
    ss.count(a);  //원소 a의 개수 반환(0 or 1)      //O(logN)
    ss.insert(a); //원소 a를 삽입                   //O(logN)
    ss.erase(it); // it가 가리키는 원소 제거        //O(logN)
    // ex) 원소 3을 제거하려면 set.erase(set.find(3))    	//O(logN)
    ss.size();         //원소의 개수 반환             	    //O(1)
    ss.clear();        // set을 완전히 비움                 //O(N)(빠름)
    ss.upper_bound(a); // a 초과인 it 반환              	//O(logN)
    ss.lower_bound(a); // a 이상인 it 반환               	//O(logN)
}

void map_example()
{
    //다른 자료형으로 연결할 때
    map<int, string> mm;
    int a = 0;

    mm.find(a);        // key a를 가리키는 it 반환             	    //O(logN)
    mm.count(a);       // key a가 몇 개 있는지 개수 반환(0 or 1)    //O(logN)
    mm.erase(a);       // key가 a인 원소를 삭제                     //O(logN)
    mm.size();         //원소의 개수 반환                     	    //O(1)
    mm.clear();        // map을 완전히 비움                         //O(N)(빠름)
    mm.upper_bound(a); // a 초과인 it 반환                          //O(logN)
    mm.lower_bound(a); // a 초과, 이상인 it 반환               	    //O(logN)
}
