#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H
/* 固定点数的基本定义。 */
typedef int fixed_t;
/* 16 个最低有效位用于小数部分。 */
#define CAL_FIXED_POINT_SHIFT_AMOUNT 16
/* 将一个值转换为固定点值。 */
#define CAL_FIXED_POINT_CONST(A) ((fixed_t)(A << CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 两个固定点值相加。 */
#define CAL_FIXED_POINT_ADD(A,B) (A + B)
/* 将固定点值 A 和整数值 B 相加。 */
#define CAL_FIXED_POINT_ADD_MIX(A,B) (A + (B << CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 两个固定点值相减。 */
#define CAL_FIXED_POINT_SUB(A,B) (A - B)
/* 从固定点值 A 中减去整数值 B。 */
#define CAL_FIXED_POINT_SUB_MIX(A,B) (A - (B << CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 将固定点值 A 乘以整数值 B。 */
#define CAL_FIXED_POINT_MULT_MIX(A,B) (A * B)
/* 将固定点值 A 除以整数值 B。 */
#define CAL_FIXED_POINT_DIV_MIX(A,B) (A / B)
/* 两个固定点值相乘。 */
#define CAL_FIXED_POINT_MULT(A,B) ((fixed_t)(((int64_t) A) * B >> CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 两个固定点值相除。 */
#define CAL_FIXED_POINT_DIV(A,B) ((fixed_t)((((int64_t) A) << CAL_FIXED_POINT_SHIFT_AMOUNT) / B))
/* 获取固定点值的整数部分。 */
#define CAL_FIXED_POINT_INT_PART(A) (A >> CAL_FIXED_POINT_SHIFT_AMOUNT)
/* 获取固定点值的四舍五入整数。 */
#define CAL_FIXED_POINT_ROUND(A) (A >= 0 ? ((A + (1 << (CAL_FIXED_POINT_SHIFT_AMOUNT - 1))) >> CAL_FIXED_POINT_SHIFT_AMOUNT) \
                : ((A - (1 << (CAL_FIXED_POINT_SHIFT_AMOUNT - 1))) >> CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 将固定点值 A 左移 B 位。 */
#define CAL_FIXED_POINT_MULT_2(A,B) (A << B)
/* 将固定点值 A 右移 B 位。 */
#define CAL_FIXED_POINT_DIV_2(A,B) (A >> B)
/* 固定点值 A 和 B 的按位异或。 */
#define CAL_FIXED_POINT_63_SUB(A,B) (A ^ B)
/* 将固定点值 A 左移 B 位后再右移 CAL_FIXED_POINT_SHIFT_AMOUNT 位。 */
#define FIXED_MULT_2_F(A, B) ((fixed_t)(((int64_t)A) << B >> CAL_FIXED_POINT_SHIFT_AMOUNT))
/* 将固定点值 A 左移 CAL_FIXED_POINT_SHIFT_AMOUNT 位后再除以 B。 */
#define CAL_FIXED_POINT_DIV_2_F(A,B) ((fixed_t)((((int64_t) A) << CAL_FIXED_POINT_SHIFT_AMOUNT) / B))
#endif /* threads/fixed-point.h */
