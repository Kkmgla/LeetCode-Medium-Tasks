## 12. Integer to Roman

Seven different symbols represent Roman numerals with the following values:  
Symbol | Value  
-------|-------  
I      | 1  
V      | 5  
X      | 10  
L      | 50  
C      | 100  
D      | 500  
M      | 1000  

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral follows these rules:  

1. **If the value does not start with 4 or 9**:  
   - Select the symbol of the maximal value that can be subtracted from the input.  
   - Append that symbol to the result.  
   - Subtract its value.  
   - Convert the remainder to a Roman numeral.  

2. **If the value starts with 4 or 9**, use the subtractive form:  
   - For example, 4 is 1 (I) less than 5 (V): `IV`.  
   - 9 is 1 (I) less than 10 (X): `IX`.  
   
   Only the following subtractive forms are used:  
   - 4 (IV)  
   - 9 (IX)  
   - 40 (XL)  
   - 90 (XC)  
   - 400 (CD)  
   - 900 (CM)  

3. **Only powers of 10 (I, X, C, M)** can be appended consecutively at most 3 times to represent multiples of 10.  
   - You cannot append 5 (V), 50 (L), or 500 (D) multiple times.  
   - If you need to append a symbol 4 times, use the subtractive form.  

### Given an integer, convert it to a Roman numeral.

### Examples  

**Example 1:**  

- **Input:** `num = 3749`  
- **Output:** `"MMMDCCXLIX"`  
- **Explanation:**  
  3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)  
   700 = DCC as 500 (D) + 100 (C) + 100 (C)  
    40 = XL as 10 (X) less of 50 (L)  
     9 = IX as 1 (I) less of 10 (X)  
  Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places  

**Example 2:**  

- **Input:** `num = 58`  
- **Output:** `"LVIII"`  
- **Explanation:**  
  50 = L  
   8 = VIII  

**Example 3:**  

- **Input:** `num = 1994`  
- **Output:** `"MCMXCIV"`  
- **Explanation:**  
  1000 = M  
   900 = CM  
    90 = XC  
     4 = IV  

### Constraints:  

- `1 <= num <= 3999`
