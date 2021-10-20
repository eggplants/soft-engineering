float bmi(float, float);
const char* rank_bmi(float);

float bmi(float height, float weight) {
  return weight / ((height / 100) * (height / 100));
}

const char* rank_bmi(float bmi) {
  if (bmi < 18.5) {
    return "slim";
  } else if (bmi < 25) {
    return "usual";
  } else if (bmi < 30) {
    return "fat lv.1";
  } else if (bmi < 35) {
    return "fat lv.2";
  } else if (bmi < 40) {
    return "fat lv.3";
  } else {
    return "fat lv.4";
  }
}

main() {
  float h, w, res;
  printf("Input your height (cm): ");
  scanf("%f", &h);
  printf("Input your weight (kg): ");
  scanf("%f", &w);
  res = bmi(h, w);
  printf("Your BMI is: %f\n", bmi(h, w));
  printf("Your BMI Rank is: %s\n", rank_bmi(res));
}
