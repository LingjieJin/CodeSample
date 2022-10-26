#include <iostream>

using namespace std;

//抽象接口
class ReplaceAlgorithm
{
public:
	virtual void DoReplace() = 0;
};
//三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void DoReplace() { cout<<"Least Recently Used replace algorithm"<<endl; }
};
 
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
	void DoReplace() { cout<<"First in First out replace algorithm"<<endl; }
};
class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
	void DoReplace() { cout<<"Random replace algorithm"<<endl; }
};

//Cache需要用到替换算法
template <class RA>
class Cache
{
private:
	RA m_ra;
public:
	Cache() { }
	~Cache() { }
	void Replace() { m_ra.DoReplace(); }
};

int main()
{
	Cache<Random_ReplaceAlgorithm> cache; //模板实参
	cache.Replace();

    Cache<FIFO_ReplaceAlgorithm> cache2;
    cache2.Replace();
	return 0;
}