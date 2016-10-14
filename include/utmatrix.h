// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  int MaxSize(const TVector &a, const TVector &b)
  {
			if (a.Size == b.Size) return a.Size;
			if (a.Size > b.Size) return a.Size
			else b.Size;
  }
  TVector() {};
  TVector(int s, int si = 0); //было s=10
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()      { return Size;       } // размер вектора
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр
  TVector  operator-(const ValType &val);   // вычесть скаляр
  TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение
  TVector  operator-(const TVector &v);     // вычитание
  ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{

	if (s < 1 || s > MAX_VECTOR_SIZE)
		throw s;
	if (si <0 || s> MAX_VECTOR_SIZE)
		throw si;
	pVector = new ValType[Size];
	Size = s;
	StartIndex = si;
	if (pVector != 0)
		for (register int i = 0; i < Size; i++)
			pVector[i] = 0;


} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[v.Size];
	for(register int i=0;i<v.Size;i++)
		pVector[i]=v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete pVector;
	pVector = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos<0 || pos>MAX_VECTOR_SIZE)
		throw pos;
	return pVector[pos-StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	bool success = 1;
	if (v.Size != Size) return 0;
	else
	{
		for (register int i = 0; i < Size; i++)
		{
			if v.pVector[i] != v.pVector[i] return 0;
		}
	}
	return 1;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if v == *this
		return 0 
	else 
		return 1;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (Size != v.Size)
	{
		Size = v.Size;
		StartIndex = v.StartIndex;
		delete pVector;
		pVector = 0;
		pVector = new ValType[Size];
	}
	for (register int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
	return *this;
	
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector tmp(Size, StartIndex);
	for (register int i = 0; i < Size; i++)
		tmp.pVector[i] = v.pVector[i] + val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector tmp(Size, StartIndex);
	for (register int i = 0; i < Size; i++)
		tmp.pVector[i] = v.pVector[i] - val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector tmp(Size, StartIndex);
	for (register int i = 0; i < Size; i++)
		tmp.pVector[i] = v.pVector[i] * val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size)
	{
		TVector tmp(MaxSize(v, *this),StartIndex)
		if (v.Size>Size)
		{
			for (register int i = 0; i < Size; i++)
				tmp.pVector[i] = v.pVector[i] + pVector[i];
			for (register int i = v.Size - Size; i < v.Size; i++)
				tmp.pVector[i] = v.pVector[i];
		}
		else
		{
			for (register int i = 0; i < v.Size; i++)
				tmp.pVector[i] = v.pVector[i] + pVector[i];
			for (register int i = Size - v.Size; i < Size; i++)
				tmp.pVector[i] = pVector[i];
		}
		*this = tmp;
	}
	for (register int i; i > Size; i++)
		pVector[i] =+ v.pVector[i];
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size)
	{
		TVector tmp(MaxSize(v, *this), StartIndex)
			if (v.Size>Size)
			{
				for (register int i = 0; i < Size; i++)
					tmp.pVector[i] = v.pVector[i]- pVector[i];
				for (register int i = v.Size - Size; i < v.Size; i++)
					tmp.pVector[i] = v.pVector[i];
			}
			else
			{
				for (register int i = 0; i < v.Size; i++)
					tmp.pVector[i] = v.pVector[i] - pVector[i];
				for (register int i = Size - v.Size; i < Size; i++)
					tmp.pVector[i] = pVector[i];
			}
		*this = tmp;
	}
	for (register int i; i > Size; i++)
		pVector[i] =- v.pVector[i];
	
	return  *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	ValType res=0;
	if (v.Size != Size)
	{
		if (Size > v.Size)
			for (register int = 0; i < Size; i++)
				res =+ (pVector[i] * v.pVector[i]);
		else
			for (register int i=0;i<v.Size;i++)
				res=+(pVector[i] * v.pVector[i]);
	}
	else
	{
		for (register int i = 0; i < Size; i++)
			res = +(pVector[i] * v.pVector[i]);
	}
	return res;
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s);           // изначально s=10;                 
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  ~TMatrix();
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	//Size = s;
	for (register int i = 0; i < s; i++)
	{
		pVector[i] = TVector<ValType>(s - i, i);
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) 
{
	if (Size != mt.Size)
	{
		Size = mt.Size;
		for (register int i = 0; i < Size; i++)
			pVector[i] = TVector<ValType>(Size - i, i);
	}
	for (register int i = 0; i < Size; i++)
	{
		pVector[i] = mt.pVector[i];
	}
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt) 
{
	*this = mt;
}
template <class ValType>
TMatrix<ValType>::~TMatrix()
{
	delete[] pVector;
	pVector = 0;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (Size != mt.Size) return 0;
	for (register int i = 0; i < si++)
	{
		if (pVector[i] != mt.pVector[i]) return 0;
	}
	return 1;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	if (Size != mt.Size) return 1;
	{
		if (pVector[i] != mt.pVector[i]) return 1;
	}
	return 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	StartIndex = mt.StartIndex;
	if (Size != mt.Size)
	{
		delete[] pVector;
		Size = mt.Size;
		StartIndex = mt.StartIndex;
			for (register int i = 0; i < Size; i++)
			{
				pVector[i] = TVector<ValType>(Size - i, i);
				pVector[i] = mt.pVector[i];
			}
	}
	for (register int i = 0; i < Size; i++)
	{
		pVector[i] = mt.pVector[i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return *this; //none
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return *this; //none
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
