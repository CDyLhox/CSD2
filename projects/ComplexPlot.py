import cmath
import matplotlib.pyplot as plt
import numpy as np

# Function to format complex numbers with 'i' instead of 'j'
def format_complex(c):
    real_part = c.real
    imag_part = c.imag
    if imag_part >= 0:
        return f"{real_part} + {imag_part}i"
    else:
        return f"{real_part} - {-imag_part}i"

# Function to calculate and print the steps for the absolute value
def calculate_absolute_with_steps(c):
    real_part = c.real
    imag_part = c.imag
    print(f"\nCalculating the absolute value of {format_complex(c)}:")
    print(f"Step 1: Square the real part: {real_part}² = {real_part**2}")
    print(f"Step 2: Square the imaginary part: {imag_part}² = {imag_part**2}")
    square_sum = real_part**2 + imag_part**2
    print(f"Step 3: Add the squares: {real_part**2} + {imag_part**2} = {square_sum}")
    sqrt_result = np.sqrt(square_sum)
    if sqrt_result.is_integer():
        print(f"Step 4: Take the square root: √({square_sum}) = {int(sqrt_result)}")
        return int(sqrt_result), f"{int(sqrt_result)}"
    else:
        print(f"Step 4: Take the square root: √({square_sum}) remains as √({square_sum})")
        return sqrt_result, f"√{square_sum}"

# Input complex numbers from the user
print("Enter the first complex number:")
real1 = float(input("Real part: "))
imag1 = float(input("Imaginary part: "))

print("\nEnter the second complex number:")
real2 = float(input("Real part: "))
imag2 = float(input("Imaginary part: "))

# Define the numbers using cmath
num1 = complex(real1, imag1)
num2 = complex(real2, imag2)

# Ask the user to choose an operation
print("\nChoose an operation:")
print("1. Add")
print("2. Subtract")
print("3. Multiply")
print("4. Divide")
operation = input("Enter the number corresponding to the operation: ")

# Perform the selected operation
if operation == "1":
    result = num1 + num2
    operation_name = "Addition"
elif operation == "2":
    result = num1 - num2
    operation_name = "Subtraction"
elif operation == "3":
    result = num1 * num2
    operation_name = "Multiplication"
elif operation == "4":
    result = num1 / num2
    operation_name = "Division"
else:
    print("Invalid operation selected.")
    exit()

# Calculate absolute values with steps
abs_num1, abs_num1_str = calculate_absolute_with_steps(num1)
abs_num2, abs_num2_str = calculate_absolute_with_steps(num2)
abs_result, abs_result_str = calculate_absolute_with_steps(result)

# Display the results with 'i'
print(f"\nVector 1: {format_complex(num1)}, Absolute value: {abs_num1_str}")
print(f"Vector 2: {format_complex(num2)}, Absolute value: {abs_num2_str}")
print(f"Result of {operation_name.lower()}: {format_complex(result)}, Absolute value: {abs_result_str}")

# Determine axis limits dynamically with a minimum range of 10
real_max = max(abs(num1.real), abs(num2.real), abs(result.real), 10)
imag_max = max(abs(num1.imag), abs(num2.imag), abs(result.imag), 10)
axis_limit = max(real_max, imag_max)  # Ensure a square plot

# Generate the graph
fig, ax = plt.subplots()

# Plot vector 1
ax.quiver(0, 0, num1.real, num1.imag, angles='xy', scale_units='xy', scale=1, color='blue', label=f'{format_complex(num1)}')

# Plot vector 2
ax.quiver(0, 0, num2.real, num2.imag, angles='xy', scale_units='xy', scale=1, color='green', label=f'{format_complex(num2)}')

# Plot the result
ax.quiver(0, 0, result.real, result.imag, angles='xy', scale_units='xy', scale=1, color='red', label=f'{format_complex(result)}')

# Add the absolute values as dashed lines
ax.plot([0, num1.real], [0, num1.imag], 'b--', label=f'|z1| = {abs_num1_str}')
ax.plot([0, num2.real], [0, num2.imag], 'g--', label=f'|z2| = {abs_num2_str}')
ax.plot([0, result.real], [0, result.imag], 'r--', label=f'|z_result| = {abs_result_str}')

# Graph settings
ax.axhline(0, color='black', linewidth=0.5)
ax.axvline(0, color='black', linewidth=0.5)
ax.set_xlim(-axis_limit, axis_limit)
ax.set_ylim(-axis_limit, axis_limit)
ax.grid(color='gray', linestyle='--', linewidth=0.5)
ax.set_aspect('equal', adjustable='box')
ax.set_title(f"Complex Numbers {operation_name} and Absolute Values")
ax.set_xlabel("Real")
ax.set_ylabel("Imaginary")
ax.legend()

# Show the graph
plt.show()
