# LBYARCH-PP2-G2-FONTILLAS-MARISTELA-S14

## Image Grayscale Float to Integer Conversion (C + x86-64 Assembly)

### Project Specification:

<img width="996" height="919" alt="image" src="https://github.com/user-attachments/assets/b35ef063-99ba-49a1-8cda-0a0fba33873b" />

### Execution Time:

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/3acc41a6-fa73-422d-a336-87506b7a2c5e" />

For the three specified timing test sizes:
- **100 pixels (10×10)**: Average execution time: 0.000000 seconds
- **10,000 pixels (100×100)**: Average execution time: 0.000000 seconds  
- **1,000,000 pixels (1000×1000)**: Average execution time: 0.000000 seconds

### Performance Analysis:

As seen above, all test sizes show 0.000000 seconds execution time, indicating the conversion process completes faster than the clock resolution.

### Program Output:

<img width="1100" height="635" alt="image" src="https://github.com/user-attachments/assets/545fc0ea-c9bb-4a96-9f2a-329a415b64fe" />

### Correctness Check:

Formula: int result = (single float pixel input * 255.0 + 0.5)

- 0.25 × 255 + 0.5 = 64.25 + 0.5 = 64.75 → **64** 
- 0.35 × 255 + 0.5 = 89.25 + 0.5 = 89.75 → **89**  
- 0.45 × 255 + 0.5 = 114.75 + 0.5 = 115.25 → **115** 
- 0.33 × 255 + 0.5 = 84.15 + 0.5 = 84.65 → **84** 
- 0.55 × 255 + 0.5 = 140.25 + 0.5 = 140.75 → **140** 
- 0.65 × 255 + 0.5 = 165.75 + 0.5 = 166.25 → **166** 
- 0.75 × 255 + 0.5 = 191.25 + 0.5 = 191.75 → **191**
- 0.33 × 255 + 0.5 = 84.15 + 0.5 = 84.65 → **84**
- 0.85 × 255 + 0.5 = 216.75 + 0.5 = 217.25 → **217** 
- 0.95 × 255 + 0.5 = 242.25 + 0.5 = 242.75 → **242** 
- 0.15 × 255 + 0.5 = 38.25 + 0.5 = 38.75 → **38**
- 0.33 × 255 + 0.5 = 84.15 + 0.5 = 84.65 → **84**

