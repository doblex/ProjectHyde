#pragma once
#include <string>

#include "Value.generated.h"

UENUM(BlueprintType)
enum EValueType
{
	STRING,
	NUMBER,
	BOOLEAN,
};



UCLASS(BlueprintType, EditInlineNew)
class PROJECTHYDE_API UValue : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	TEnumAsByte<EValueType> Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FString StringValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	double Number;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	bool Boolean;
	
	//Default constructor
	UValue() : Type(NUMBER), Number(0) {}
	
	//String constructors
	UValue(const char *string) : Type(STRING), StringValue(string) {}
	UValue(const FString &string) : Type(STRING), StringValue(string) {}
	
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
	
	const FString GetStringValue()
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
			return FCString::Atof(*StringValue);
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

	const FString ConvertToString()
	{
		switch (Type)
		{
		case STRING:
			return StringValue;
		case BOOLEAN:
			return Boolean ? "True" : "False";
		case NUMBER:
			if (FMath::IsNearlyEqual(Number, FMath::RoundToFloat(Number)))
			{
				return FString::FromInt(FMath::RoundToInt(Number));
			}
			else
			{
				return FString::SanitizeFloat(Number);
			}
		default:
			return "<unknown>";
		}
	}
};
