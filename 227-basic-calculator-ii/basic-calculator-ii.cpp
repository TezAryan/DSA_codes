class Solution {
public:
    int calculate(string expression) {
        
            vector<long long> values;

    long long currentNumber = 0;
    char previousOperator = '+';

    int length = expression.size();

    for (int position = 0; position <= length; position++)
    {
        char currentChar =
            (position == length) ? '+' : expression[position];

        if (isdigit(currentChar))
        {
            currentNumber =
                currentNumber * 10 + (currentChar - '0');
        }

        if ((!isdigit(currentChar) && currentChar != ' ')
            || position == length)
        {
            if (previousOperator == '+')
            {
                values.push_back(currentNumber);
            }
            else if (previousOperator == '-')
            {
                values.push_back(-currentNumber);
            }
            else if (previousOperator == '*')
            {
                long long lastValue = values.back();
                values.pop_back();

                values.push_back(lastValue * currentNumber);
            }
            else if (previousOperator == '/')
            {
                long long lastValue = values.back();
                values.pop_back();

                values.push_back(lastValue / currentNumber);
            }

            previousOperator = currentChar;
            currentNumber = 0;
        }
    }

    long long answer = 0;

    for (long long value : values)
    {
        answer += value;
    }

    return (int)answer;
}
    
};