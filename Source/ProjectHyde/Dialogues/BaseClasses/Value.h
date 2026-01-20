#pragma once
#include <string>

#include "Value.generated.h"

UCLASS()
class PROJECTHYDE_API UValue : public UObject
{
	GENERATED_BODY()
	
public:
	enum EValueType
	{
		STRING,
		NUMBER,
		BOOLEAN,
	};
	
	
	EValueType Type;

	std::string StringValue;
	double Number;
	bool Boolean;
	
	//Default constructor
	UValue() : Type(NUMBER), Number(0) {}
	
	//String constructors
	UValue(const char *string) : Type(STRING), StringValue(std::string(string)) {}
	UValue(const std::string &string) : Type(STRING), StringValue(string) {}
	
	//Number Constructors
	UValue(float Number) : Type(NUMBER), Number(Number) {}
	UValue(double Number) : Type(NUMBER), Number(Number) {}
	UValue(int Number) : Type(NUMBER), Number(Number) {}
	
	//Boolean Constructors
	UValue(bool Boolean) : Type(BOOLEAN), Boolean(Boolean) {}
	
	EValueType GetType() const { return Type; }
	
	bool IsString() const
	{
		return GetType() == STRING;
	}

	bool IsNumber() const
	{
		return GetType() == NUMBER;
	}

	bool IsBoolean() const
	{
		return GetType() == BOOLEAN;
	}
	
	const std::string GetStringValue()
	{
		if (this->Type == STRING)
		{
			return this->StringValue;
		}

			return "";
	}

	float GetNumberValue()
	{
		if (this->Type == NUMBER)
		{
			return this->Number;
		}
			return 0;
	}

	float ConvertToNumber()
	{
		if (Type == STRING)
		{
			return atof(StringValue.c_str());
		}
		if (Type == BOOLEAN)
		{
			return Boolean ? 1 : 0;
		}
		return Number;
	}

	bool GetBooleanValue()
	{
		if (this->Type == BOOLEAN)
		{
			return this->Boolean;
		}

			return false;
	}

	const std::string ConvertToString()
	{
		switch (Type)
		{
		case STRING:
			return StringValue;
		case BOOLEAN:
			return Boolean ? "True" : "False";
		case NUMBER:
			if (trunc(Number) == Number)
			{
				return std::to_string((int)Number);
			}
			else
			{
				return std::to_string(Number);
			}
		default:
			return "<unknown>";
		}
	}
};
