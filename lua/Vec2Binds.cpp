#include "Vec2.h"
#include "LuaStack.h"
#include "LuaEnvironment.h"


namespace crown
{

extern "C"
{

int32_t	vec2(lua_State* L)
{
	LuaStack stack(L);

	float x = stack.get_float(1);
	float y = stack.get_float(2);

	Vec2* vec = next_vec2();

	vec->x = x;
	vec->y = y;

	stack.push_vec2(vec);

	return 1;
}

int32_t vec2_values(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*)stack.get_vec2(1);

	float x = a->x;
	float y = a->y;

	stack.push_float(x);
	stack.push_float(y);

	return 2;
}


int32_t vec2_add(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*)stack.get_vec2(1);
	Vec2* b = (Vec2*)stack.get_vec2(2);

	*a += *b;

	stack.push_vec2(a);

	return 1;
}

int32_t vec2_subtract(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	*a -= *b;

	stack.push_vec2(a);

	return 1;
}

int32_t vec2_multiply(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);
	float k = stack.get_float(2);

	*a *= k;

	stack.push_vec2(a);

	return 1;
}			
	
int32_t vec2_divide(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	float k = stack.get_float(2);

	*a /= k;

	stack.push_vec2(a);

	return 1;
}

int32_t vec2_dot(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	stack.push_float(a->dot(*b));

	return 1;
}

int32_t vec2_equals(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	stack.push_bool(*a == *b);

	return 1;
}

int32_t vec2_lower(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	stack.push_bool(*a < *b);

	return 1;
}

int32_t vec2_greater(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);
	
	stack.push_bool(*a > *b);

	return 1;
}

int32_t vec2_length(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);

	stack.push_float(a->length());

	return 1;
}

int32_t vec2_squared_length(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);

	stack.push_float(a->squared_length());

	return 1;
}

int32_t vec2_set_length(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);
	float len = stack.get_float(2);

	a->set_length(len);

	return 0;
}

int32_t	vec2_normalize(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);

	a->normalize();

	stack.push_vec2(a);

	return 1;
}

int32_t	vec2_negate(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);

	a->negate();

	stack.push_vec2(a);

	return 1;
}

int32_t	vec2_get_distance_to(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	stack.push_float(a->get_distance_to(*b));

	return 1;
}

int32_t	vec2_get_angle_between(lua_State* L)
{
	LuaStack stack(L);
	
	Vec2* a = (Vec2*) stack.get_vec2(1);
	Vec2* b = (Vec2*) stack.get_vec2(2);

	stack.push_float(a->get_angle_between(*b));

	return 1;
}

int32_t	vec2_zero(lua_State* L)
{
	LuaStack stack(L);

	Vec2* a = (Vec2*) stack.get_vec2(1);

	a->zero();

	return 0;
}

} // extern "C"

void load_vec2(LuaEnvironment& env)
{
	env.load_module_function("Vec2", "new", vec2);
	env.load_module_function("Vec2", "val", vec2_values);
	env.load_module_function("Vec2", "add", vec2_add);
	env.load_module_function("Vec2", "sub", vec2_subtract);
	env.load_module_function("Vec2", "mul", vec2_multiply);
	env.load_module_function("Vec2", "div", vec2_divide);
	env.load_module_function("Vec2", "dot", vec2_dot);
	env.load_module_function("Vec2", "equals", vec2_equals);
	env.load_module_function("Vec2", "lower", vec2_lower);
	env.load_module_function("Vec2", "greater", vec2_greater);
	env.load_module_function("Vec2", "length", vec2_length);
	env.load_module_function("Vec2", "squared_length", vec2_squared_length);
	env.load_module_function("Vec2", "set_length", vec2_set_length);
	env.load_module_function("Vec2", "normalize", vec2_normalize);
	env.load_module_function("Vec2", "negate", vec2_negate);
	env.load_module_function("Vec2", "get_distance_to", vec2_get_distance_to);
	env.load_module_function("Vec2", "get_angle_between", vec2_get_angle_between);
	env.load_module_function("Vec2", "zero", vec2_zero);
}

} // namespace crown