/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Lenovo/Desktop/exp3.1static_sequence_generator/button_led_buzzer.v";
static unsigned int ng1[] = {100000000U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {100000U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {14U, 0U};
static unsigned int ng8[] = {13U, 0U};
static unsigned int ng9[] = {4U, 0U};
static unsigned int ng10[] = {11U, 0U};
static unsigned int ng11[] = {8U, 0U};
static unsigned int ng12[] = {7U, 0U};
static unsigned int ng13[] = {12U, 0U};
static unsigned int ng14[] = {15U, 0U};
static unsigned int ng15[] = {16U, 0U};
static unsigned int ng16[] = {5U, 0U};
static unsigned int ng17[] = {9U, 0U};
static unsigned int ng18[] = {6U, 0U};
static unsigned int ng19[] = {10U, 0U};
static unsigned int ng20[] = {60000U, 0U};
static unsigned int ng21[] = {20000U, 0U};
static int ng22[] = {1, 0};
static int ng23[] = {0, 0};
static unsigned int ng24[] = {184U, 0U};



static void Always_40_0(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;

LAB0:    t1 = (t0 + 5152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 7704);
    *((int *)t2) = 1;
    t3 = (t0 + 5184);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2792);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t4, 32, t5, 32);
    t6 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 32, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(42, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 32, 0LL);
    goto LAB11;

}

static void Always_50_1(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;

LAB0:    t1 = (t0 + 5400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 7720);
    *((int *)t2) = 1;
    t3 = (t0 + 5432);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 2952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(57, ng0);

LAB13:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2952);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 17, t4, 17, t5, 17);
    t6 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(52, ng0);

LAB12:    xsi_set_current_line(53, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 17, 0LL);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_64_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 7736);
    *((int *)t2) = 1;
    t3 = (t0 + 5680);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(65, ng0);

LAB5:    xsi_set_current_line(66, ng0);
    t4 = (t0 + 3272);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(68, ng0);
    t9 = (t0 + 3112);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB20:    goto LAB17;

LAB9:    xsi_set_current_line(73, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB23:    goto LAB17;

LAB11:    xsi_set_current_line(78, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB26:    goto LAB17;

LAB13:    xsi_set_current_line(83, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB29:    goto LAB17;

LAB18:    xsi_set_current_line(69, ng0);
    t18 = ((char*)((ng3)));
    t19 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t19, t18, 0, 0, 3, 0LL);
    goto LAB20;

LAB21:    xsi_set_current_line(74, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB23;

LAB24:    xsi_set_current_line(79, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB26;

LAB27:    xsi_set_current_line(84, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB29;

}

static void Always_94_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 5896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 7752);
    *((int *)t2) = 1;
    t3 = (t0 + 5928);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(95, ng0);

LAB5:    xsi_set_current_line(96, ng0);
    t4 = (t0 + 3272);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(137, ng0);

LAB70:    xsi_set_current_line(138, ng0);
    t2 = ((char*)((ng14)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng15)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 5, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(97, ng0);

LAB18:    xsi_set_current_line(98, ng0);
    t9 = ((char*)((ng7)));
    t10 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 4, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 1752U);
    t3 = *((char **)t2);

LAB19:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB28;

LAB29:
LAB30:    goto LAB17;

LAB9:    xsi_set_current_line(107, ng0);

LAB31:    xsi_set_current_line(108, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 1752U);
    t4 = *((char **)t2);

LAB32:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB41;

LAB42:
LAB43:    goto LAB17;

LAB11:    xsi_set_current_line(117, ng0);

LAB44:    xsi_set_current_line(118, ng0);
    t5 = ((char*)((ng10)));
    t7 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 4, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 1752U);
    t5 = *((char **)t2);

LAB45:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB54;

LAB55:
LAB56:    goto LAB17;

LAB13:    xsi_set_current_line(127, ng0);

LAB57:    xsi_set_current_line(128, ng0);
    t7 = ((char*)((ng12)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 4, 0LL);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 1752U);
    t7 = *((char **)t2);

LAB58:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB63;

LAB64:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB67;

LAB68:
LAB69:    goto LAB17;

LAB20:    xsi_set_current_line(100, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB22:    xsi_set_current_line(101, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB24:    xsi_set_current_line(102, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB26:    xsi_set_current_line(103, ng0);
    t4 = ((char*)((ng13)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB28:    xsi_set_current_line(104, ng0);
    t4 = ((char*)((ng15)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB33:    xsi_set_current_line(110, ng0);
    t5 = ((char*)((ng3)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB35:    xsi_set_current_line(111, ng0);
    t5 = ((char*)((ng16)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB37:    xsi_set_current_line(112, ng0);
    t5 = ((char*)((ng17)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB39:    xsi_set_current_line(113, ng0);
    t5 = ((char*)((ng8)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB41:    xsi_set_current_line(114, ng0);
    t5 = ((char*)((ng15)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB46:    xsi_set_current_line(120, ng0);
    t7 = ((char*)((ng6)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB48:    xsi_set_current_line(121, ng0);
    t7 = ((char*)((ng18)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB50:    xsi_set_current_line(122, ng0);
    t7 = ((char*)((ng19)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB52:    xsi_set_current_line(123, ng0);
    t7 = ((char*)((ng7)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB54:    xsi_set_current_line(124, ng0);
    t7 = ((char*)((ng15)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB59:    xsi_set_current_line(130, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB61:    xsi_set_current_line(131, ng0);
    t9 = ((char*)((ng12)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB63:    xsi_set_current_line(132, ng0);
    t9 = ((char*)((ng10)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB65:    xsi_set_current_line(133, ng0);
    t9 = ((char*)((ng14)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB67:    xsi_set_current_line(134, ng0);
    t9 = ((char*)((ng15)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

}

static void Always_147_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 6144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 7768);
    *((int *)t2) = 1;
    t3 = (t0 + 6176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(148, ng0);
    t4 = (t0 + 3432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3592);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 5, 0LL);
    goto LAB2;

}

static void Always_151_5(char *t0)
{
    char t8[8];
    char t34[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;

LAB0:    t1 = (t0 + 6392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 7784);
    *((int *)t2) = 1;
    t3 = (t0 + 6424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(152, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng20)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 3592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3432);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t4 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB13;

LAB12:    if (t20 != 0)
        goto LAB14;

LAB15:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 3592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3432);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t4 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB22;

LAB19:    if (t20 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t8) = 1;

LAB22:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB23;

LAB24:
LAB25:
LAB18:
LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(153, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 20, 0LL);
    goto LAB11;

LAB13:    *((unsigned int *)t8) = 1;
    goto LAB15;

LAB14:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB15;

LAB16:    xsi_set_current_line(155, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 20, 0LL);
    goto LAB18;

LAB21:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(157, ng0);
    t30 = (t0 + 3752);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = ((char*)((ng3)));
    memset(t34, 0, 8);
    xsi_vlog_unsigned_add(t34, 20, t32, 20, t33, 20);
    t35 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t35, t34, 0, 0, 20, 0LL);
    goto LAB25;

}

static void Always_160_6(char *t0)
{
    char t8[8];
    char t12[8];
    char t28[8];
    char t44[8];
    char t52[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    int t76;
    int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 6640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 7800);
    *((int *)t2) = 1;
    t3 = (t0 + 6672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(161, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng21)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB6;

LAB5:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB6;

LAB9:    if (*((unsigned int *)t6) < *((unsigned int *)t7))
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB8:    memset(t12, 0, 8);
    t13 = (t8 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t13) != 0)
        goto LAB12;

LAB13:    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t20);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB14;

LAB15:    memcpy(t52, t12, 8);

LAB16:    t84 = (t52 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (~(t85));
    t87 = *((unsigned int *)t52);
    t88 = (t87 & t86);
    t89 = (t88 != 0);
    if (t89 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);

LAB30:    goto LAB2;

LAB6:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB8;

LAB10:    *((unsigned int *)t12) = 1;
    goto LAB13;

LAB12:    t19 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB13;

LAB14:    t24 = (t0 + 3592);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng15)));
    memset(t28, 0, 8);
    t29 = (t26 + 4);
    t30 = (t27 + 4);
    t31 = *((unsigned int *)t26);
    t32 = *((unsigned int *)t27);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t29);
    t35 = *((unsigned int *)t30);
    t36 = (t34 ^ t35);
    t37 = (t33 | t36);
    t38 = *((unsigned int *)t29);
    t39 = *((unsigned int *)t30);
    t40 = (t38 | t39);
    t41 = (~(t40));
    t42 = (t37 & t41);
    if (t42 != 0)
        goto LAB18;

LAB17:    if (t40 != 0)
        goto LAB19;

LAB20:    memset(t44, 0, 8);
    t45 = (t28 + 4);
    t46 = *((unsigned int *)t45);
    t47 = (~(t46));
    t48 = *((unsigned int *)t28);
    t49 = (t48 & t47);
    t50 = (t49 & 1U);
    if (t50 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t45) != 0)
        goto LAB23;

LAB24:    t53 = *((unsigned int *)t12);
    t54 = *((unsigned int *)t44);
    t55 = (t53 & t54);
    *((unsigned int *)t52) = t55;
    t56 = (t12 + 4);
    t57 = (t44 + 4);
    t58 = (t52 + 4);
    t59 = *((unsigned int *)t56);
    t60 = *((unsigned int *)t57);
    t61 = (t59 | t60);
    *((unsigned int *)t58) = t61;
    t62 = *((unsigned int *)t58);
    t63 = (t62 != 0);
    if (t63 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB18:    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB19:    t43 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t44) = 1;
    goto LAB24;

LAB23:    t51 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB24;

LAB25:    t64 = *((unsigned int *)t52);
    t65 = *((unsigned int *)t58);
    *((unsigned int *)t52) = (t64 | t65);
    t66 = (t12 + 4);
    t67 = (t44 + 4);
    t68 = *((unsigned int *)t12);
    t69 = (~(t68));
    t70 = *((unsigned int *)t66);
    t71 = (~(t70));
    t72 = *((unsigned int *)t44);
    t73 = (~(t72));
    t74 = *((unsigned int *)t67);
    t75 = (~(t74));
    t76 = (t69 & t71);
    t77 = (t73 & t75);
    t78 = (~(t76));
    t79 = (~(t77));
    t80 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t80 & t78);
    t81 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t81 & t79);
    t82 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t82 & t78);
    t83 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t83 & t79);
    goto LAB27;

LAB28:    xsi_set_current_line(162, ng0);
    t90 = (t0 + 3592);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t93, t92, 0, 0, 5, 0LL);
    goto LAB30;

}

static void Cont_167_7(char *t0)
{
    char t3[8];
    char t4[8];
    char t10[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;

LAB0:    t1 = (t0 + 6888U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 3592);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3432);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB5;

LAB4:    if (t22 != 0)
        goto LAB6;

LAB7:    memset(t4, 0, 8);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t26) != 0)
        goto LAB10;

LAB11:    t33 = (t4 + 4);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t33);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB12;

LAB13:    t38 = *((unsigned int *)t4);
    t39 = (~(t38));
    t40 = *((unsigned int *)t33);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t33) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t42, 8);

LAB20:    t43 = (t0 + 7928);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t47, 0, 8);
    t48 = 1U;
    t49 = t48;
    t50 = (t3 + 4);
    t51 = *((unsigned int *)t3);
    t48 = (t48 & t51);
    t52 = *((unsigned int *)t50);
    t49 = (t49 & t52);
    t53 = (t47 + 4);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t54 | t48);
    t55 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t55 | t49);
    xsi_driver_vfirst_trans(t43, 0, 0);
    t56 = (t0 + 7816);
    *((int *)t56) = 1;

LAB1:    return;
LAB5:    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB6:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t32 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB11;

LAB12:    t37 = ((char*)((ng22)));
    goto LAB13;

LAB14:    t42 = ((char*)((ng23)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t37, 32, t42, 32);
    goto LAB20;

LAB18:    memcpy(t3, t37, 8);
    goto LAB20;

}

static void Always_176_8(char *t0)
{
    char t8[8];
    char t32[8];
    char t33[8];
    char t41[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;

LAB0:    t1 = (t0 + 7136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 7832);
    *((int *)t2) = 1;
    t3 = (t0 + 7168);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(177, ng0);
    t4 = (t0 + 3912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng14)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(193, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB33;

LAB30:    if (t20 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t8) = 1;

LAB33:    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(201, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB36:
LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(178, ng0);

LAB12:    xsi_set_current_line(179, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2632);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 4232);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng11)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB16;

LAB13:    if (t20 != 0)
        goto LAB15;

LAB14:    *((unsigned int *)t8) = 1;

LAB16:    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(185, ng0);

LAB21:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 2792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB25;

LAB22:    if (t20 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t8) = 1;

LAB25:    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB26;

LAB27:
LAB28:
LAB19:    goto LAB11;

LAB15:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB16;

LAB17:    xsi_set_current_line(181, ng0);

LAB20:    xsi_set_current_line(182, ng0);
    t23 = ((char*)((ng3)));
    t24 = (t0 + 2632);
    xsi_vlogvar_assign_value(t24, t23, 0, 0, 1);
    goto LAB19;

LAB24:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(187, ng0);

LAB29:    xsi_set_current_line(188, ng0);
    t23 = (t0 + 4072);
    t24 = (t23 + 56U);
    t30 = *((char **)t24);
    memset(t33, 0, 8);
    t31 = (t33 + 4);
    t34 = (t30 + 4);
    t35 = *((unsigned int *)t30);
    t36 = (t35 >> 15);
    t37 = (t36 & 1);
    *((unsigned int *)t33) = t37;
    t38 = *((unsigned int *)t34);
    t39 = (t38 >> 15);
    t40 = (t39 & 1);
    *((unsigned int *)t31) = t40;
    t42 = (t0 + 4072);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    memset(t41, 0, 8);
    t45 = (t41 + 4);
    t46 = (t44 + 4);
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 0);
    *((unsigned int *)t41) = t48;
    t49 = *((unsigned int *)t46);
    t50 = (t49 >> 0);
    *((unsigned int *)t45) = t50;
    t51 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t51 & 32767U);
    t52 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t52 & 32767U);
    xsi_vlogtype_concat(t32, 16, 16, 2U, t41, 15, t33, 1);
    t53 = (t0 + 4072);
    xsi_vlogvar_assign_value(t53, t32, 0, 0, 16);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 4232);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 4, t4, 4, t5, 4);
    t6 = (t0 + 4232);
    xsi_vlogvar_assign_value(t6, t8, 0, 0, 4);
    goto LAB28;

LAB32:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(194, ng0);

LAB37:    xsi_set_current_line(196, ng0);
    t23 = ((char*)((ng24)));
    t24 = (t0 + 4072);
    xsi_vlogvar_assign_value(t24, t23, 0, 0, 16);
    xsi_set_current_line(197, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(198, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB36;

}

static void Cont_205_9(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 7384U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(205, ng0);
    t2 = (t0 + 4072);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 8);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 8);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t13 & 255U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 255U);
    xsi_vlogtype_concat(t3, 8, 8, 1U, t4, 8);
    t15 = (t0 + 7992);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memset(t19, 0, 8);
    t20 = 255U;
    t21 = t20;
    t22 = (t3 + 4);
    t23 = *((unsigned int *)t3);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t22);
    t21 = (t21 & t24);
    t25 = (t19 + 4);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t26 | t20);
    t27 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t27 | t21);
    xsi_driver_vfirst_trans(t15, 0, 7);
    t28 = (t0 + 7848);
    *((int *)t28) = 1;

LAB1:    return;
}


extern void work_m_00000000001125167392_1026299294_init()
{
	static char *pe[] = {(void *)Always_40_0,(void *)Always_50_1,(void *)Always_64_2,(void *)Always_94_3,(void *)Always_147_4,(void *)Always_151_5,(void *)Always_160_6,(void *)Cont_167_7,(void *)Always_176_8,(void *)Cont_205_9};
	xsi_register_didat("work_m_00000000001125167392_1026299294", "isim/button_tb_isim_beh.exe.sim/work/m_00000000001125167392_1026299294.didat");
	xsi_register_executes(pe);
}
