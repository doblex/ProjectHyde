#pragma once
#include <string>

#include "Value.generated.h"

UENUM(BlueprintType)
enum class EValueType : uint8
{
	String,
	Number,
	Boolean,
};



UCLASS(BlueprintType, EditInlineNew)
class PROJECTHYDE_API UValue : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	EValueType Type = EValueType::String;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FString StringValue = "";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	double Number = 0.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	bool Boolean = false;
	
	
	static UValue* MakeString(UObject* Outer, const FString& InString)
	{
		UValue* V = NewObject<UValue>(Outer);
		V->Type = EValueType::String;
		V->StringValue = InString;
		return V;
	}

	static UValue* MakeNumber(UObject* Outer, double InNumber)
	{
		UValue* V = NewObject<UValue>(Outer);
		V->Type = EValueType::Number;
		V->Number = InNumber;
		return V;
	}

	static UValue* MakeBoolean(UObject* Outer, bool bInBoolean)
	{
		UValue* V = NewObject<UValue>(Outer);
		V->Type = EValueType::Boolean;
		V->Boolean = bInBoolean;
		return V;
	}
	
	EValueType GetType() const { return Type; }
	
	bool IsString() const
	{
		return GetType() == EValueType::String;
	}

	bool IsNumber() const
	{
		return GetType() == EValueType::Number;
	}

	bool IsBoolean() const
	{
		return GetType() == EValueType::Boolean;
	}
	
	const FString GetStringValue()
	{
		if (this->Type == EValueType::String)
		{
			return this->StringValue;
		}

			return "";
	}

	float GetNumberValue()
	{
		if (this->Type == EValueType::Number)
		{
			return this->Number;
		}
			return 0;
	}

	float ConvertToNumber()
	{
		if (Type == EValueType::String)
		{
			return FCString::Atof(*StringValue);
		}
		if (Type == EValueType::Boolean)
		{
			return Boolean ? 1 : 0;
		}
		return Number;
	}

	bool GetBooleanValue()
	{
		if (this->Type == EValueType::Boolean)
		{
			return this->Boolean;
		}

			return false;
	}

	const FString ConvertToString()
	{
		switch (Type)
		{
		case EValueType::String:
			return StringValue;
		case EValueType::Boolean:
			return Boolean ? "True" : "False";
		case EValueType::Number:
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
