import joblib
import m2cgen as m2c

# Load your saved model
model = joblib.load("decision_tree_model.pkl")

# Convert to C code
c_code = m2c.export_to_c(model)

# Save C code to a file
with open("cache_replacement_model.c", "w") as f:
    f.write(c_code)

print("✅ C code successfully generated as cache_replacement_model.c")
