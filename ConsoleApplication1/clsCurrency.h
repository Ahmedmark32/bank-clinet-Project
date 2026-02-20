#pragma once
#include<iostream>
#include"clsString.h"
#include<string>
#include<vector>
#include<fstream>


class clsCurrency
{
private:

	enum enMode{EmptyMode=0 , UpdateMode=1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData;
		vCurrencyData = clsString::Split(Line,Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1],
			vCurrencyData[2],stof(vCurrencyData[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}

	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		fstream MyFile;

		MyFile.open("Currencies.txt",ios::in);

		vector <clsCurrency> vCurrencys;

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))
			{
				clsCurrency CurrencyData = ConvertLineToCurrencyObject(DataLine);

				vCurrencys.push_back(CurrencyData);

			}

			MyFile.close();
		}
		
		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector<clsCurrency> vCurrencys;
		vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency &C : vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(vCurrencys);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode,string Country,string CurrencyCode,
			string CurrencyName, float Rate )
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
		
	}

	 bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country() 
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{	
			string DataLine;

			while (getline(MyFile,DataLine))

			{
				clsCurrency Currency = ConvertLineToCurrencyObject(DataLine);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))

			{
				clsCurrency Currency = ConvertLineToCurrencyObject(DataLine);

				if (clsString::LowerAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExit(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
			return (!Currency.IsEmpty());
	}

	float ConvertToUSD(float Amount)
	{
		return float(Amount / Rate());

	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{	
		if (CurrencyCode() == "USD")
		{
			return (Amount * Currency2.Rate());

		}

		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return Amount;
		}

		
		return float(Amount * Currency2.Rate());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();

	};

};

