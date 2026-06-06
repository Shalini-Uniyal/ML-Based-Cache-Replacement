#include <stdio.h>

// Decision Tree–based cache replacement function
int predict_cache_action(float recency, float frequency, float priority) {
    // Simulating learned decision rules from your Python model
    if (recency < 0.4) {
        if (frequency < 0.3) {
            return 0;  // Replace (low usage, old)
        } else {
            if (priority > 0.5)
                return 1;  // Keep (recent + important)
            else
                return 0;  // Replace (recent but low priority)
        }
    } else {
        if (frequency > 0.7)
            return 1;  // Keep (frequently used)
        else
            return 0;  // Replace (less frequent, not recent)
    }
}

// Test the function
int main() {
    float recency, frequency, priority;
    printf("Enter recency, frequency, priority values (0 to 1): ");
    scanf("%f %f %f", &recency, &frequency, &priority);

    int action = predict_cache_action(recency, frequency, priority);

    if (action == 1)
        printf("✅ Cache Block KEPT (Model predicts reuse soon)\n");
    else
        printf("🗑️ Cache Block REPLACED (Model predicts no reuse soon)\n");

    return 0;
}
