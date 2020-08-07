#pragma once
class Health
{
public:
	Health();
	Health(float mHP);
	~Health();

	float curHealth;

	float GetMaxHealth();
	void  SetMaxHealth(float mHP);
	void  TakeDamage(float dmg);
	void  HealDamage(float heal);
	void  SetCurrentHealth(float cHP);
	void  ResetHealth();
	void  InitHealth(float mHP);
private:
	float maxHealth;
};

