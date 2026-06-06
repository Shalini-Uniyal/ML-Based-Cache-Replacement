import os
import joblib
import m2cgen as m2c

# Current file location
current_dir = os.path.dirname(os.path.abspath(__file__))

# Load model
model_path = os.path.join(current_dir, "decision_tree_model.pkl")
model = joblib.load(model_path)

# Convert to C
c_code = m2c.export_to_c(model)

# Output path
output_dir = os.path.join(current_dir, "..", "generated_code")
os.makedirs(output_dir, exist_ok=True)

output_file = os.path.join(output_dir, "cache_replacement_model.c")

with open(output_file, "w") as f:
    f.write(c_code)

print(" C code successfully generated!")
print("Saved to:", output_file)