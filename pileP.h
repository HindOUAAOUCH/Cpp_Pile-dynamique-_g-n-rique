#pragma once
#include <iostream>
using namespace std;
template <class T>
class pileP
{
private:
	T val;
	pileP* svt;
public:
	pileP();
	void afficher()const;
	pileP<T>& operator=(const pileP<T>& P);
	void emplier(const T& x);
	T depiler();
	bool estVide() const;
	~pileP();
};

template<class T>
inline pileP<T>::pileP()
{
	svt = nullptr;
	std::cout << "const de la pile" << std::endl;
}

template<class T>
inline void pileP<T>::afficher() const
{
	cout << "----- afficher pile :-----" << endl;
	pileP<T>* temp = svt;
	while (temp)
	{
		cout << " " << temp->val << endl;
		temp = temp->svt;
	}
	delete temp;
}

template<class T>
inline pileP<T>& pileP<T>::operator=(const pileP<T>& P)
{
	// TODO: insérer une instruction return ici
	this->val = P.val;
	this->svt = P.svt;
	return *this;
}



template<class T>
inline void pileP<T>::emplier(const T& x)
{
	pileP<T>* NE=new pileP<T>();
		NE->val = x;
		NE->svt = this->svt;
		this->svt= NE;		
}

template<class T>
inline T pileP<T>::depiler()
{
	T value = svt->val;
	pileP<T>* temp = this->svt;
	this->svt = this->svt->svt;
	delete temp;
	return value;
}

template<class T>
inline bool pileP<T>::estVide() const
{
	return (this->svt == nullptr);
}

template<class T>
inline pileP<T>::~pileP()
{
	std::cout << "detruc de la pile" << std::endl;
}