#include "Health.h"

Health::Health()
{}

Health::Health(float mHP)
{
	maxHealth = mHP;
	curHealth = maxHealth;
}

Health::~Health()
{}

float Health::GetMaxHealth()
{
	return maxHealth;
}

void Health::InitHealth(float mHP)
{
	maxHealth = mHP;
	curHealth = maxHealth;
}
void Health::SetMaxHealth(float mHP)
{
	maxHealth = mHP;
}
void Health::TakeDamage(float dmg)
{
	curHealth -= dmg;
	if (curHealth <= 0)
		curHealth = 0;
}
void Health::HealDamage(float heal)
{
	curHealth += heal;
	if (curHealth > maxHealth)
		curHealth = maxHealth;
}
void Health::SetCurrentHealth(float cHP)
{
	curHealth = cHP;
}
void Health::ResetHealth()
{
	curHealth = maxHealth;
}
