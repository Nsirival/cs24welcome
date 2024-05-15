#include "Person.h"

Person::Person(const std::string &name, Gender gender)
{
    thename = name;
    thegender = gender;
    themother = nullptr;
    thefather = nullptr;
}

void Person::getancestors(Person *person, std::set<Person *> &ancestors) const
{
    if (person != nullptr)
    {
        ancestors.insert(person);
        getancestors(person->mother(), ancestors);
        getancestors(person->father(), ancestors);
    }
};

void Person::getdescendants(Person *person, std::set<Person *> &descendants) const
{
    if (person != nullptr)
    {
        descendants.insert(person);
        for (Person *child : person->children())
        {
            getdescendants(child, descendants);
        }
    }
};

std::set<Person *> Person::ancestors(PMod pmod = PMod::ANY)
{
    std::set<Person *> fin;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        getancestors(mother(), fin);
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        getancestors(father(), fin);
    }
    return fin;
};
std::set<Person *> Person::aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    for (Person *i : parents(pmod))
    {
        for (Person *j : i->siblings(PMod::ANY, smod))
        {
            if (j->gender() == Gender::FEMALE)
            {
                fin.insert(j);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *s : pa->children())
        {
            if (s != this && s->gender() == Gender::MALE)
            {
                if ((s->mother() == mother() && s->father() == father()) && smod == SMod::FULL)
                {
                    fin.insert(s);
                }
                else if ((s->mother() == mother() || s->father() == father()) && smod == SMod::HALF)
                {
                    fin.insert(s);
                }
                else
                {
                    fin.insert(s);
                }
            }
        }
    }
    return fin;
};
std::set<Person *> Person::children()
{
    return thechildren;
};
std::set<Person *> Person::cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    for (Person *s : siblings(pmod, smod))
    {
        for (Person *k : s->children())
        {
            fin.insert(k);
        }
    }
    return fin;
};
std::set<Person *> Person::daughters()
{
    std::set<Person *> fin;
    for (Person *p : thechildren)
    {
        if (p->gender() == Gender::FEMALE)
        {
            fin.insert(p);
        }
    }
    return fin;
};
std::set<Person *> Person::descendants()
{
    std::set<Person *> fin;
    getdescendants(this, fin);
    return fin;
};
std::set<Person *> Person::grandchildren()
{
    std::set<Person *> fin;
    for (Person *c : thechildren)
    {
        for (Person *g : c->children())
        {
            fin.insert(g);
        }
    }
    return fin;
};
std::set<Person *> Person::granddaughters()
{
    std::set<Person *> fin;
    for (Person *c : thechildren)
    {
        for (Person *g : c->children())
        {
            if (g->gender() == Gender::FEMALE)
            {
                fin.insert(g);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::grandfathers(PMod pmod = PMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *g : pa->parents())
        {
            if (g->gender() == Gender::MALE)
            {
                fin.insert(g);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::grandmothers(PMod pmod = PMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *g : pa->parents())
        {
            if (g->gender() == Gender::FEMALE)
            {
                fin.insert(g);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::grandparents(PMod pmod = PMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *g : pa->parents())
        {
            fin.insert(g);
        }
    }
    return fin;
};
std::set<Person *> Person::grandsons()
{
    std::set<Person *> fin;
    for (Person *c : thechildren)
    {
        for (Person *g : c->children())
        {
            if (g->gender() == Gender::MALE)
            {
                fin.insert(g);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    for (Person *s : siblings(pmod, smod))
    {
        for (Person *k : s->children())
        {
            if (k->gender() == Gender::MALE)
            {
                fin.insert(k);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    for (Person *s : siblings(pmod, smod))
    {
        for (Person *k : s->children())
        {
            if (k->gender() == Gender::FEMALE)
            {
                fin.insert(k);
            }
        }
    }
    return fin;
};
std::set<Person *> Person::parents(PMod pmod = PMod::ANY)
{
    std::set<Person *> fin;
    if (pmod == PMod::ANY || pmod == PMod::MATERNAL)
    {
        fin.insert(themother);
    }
    if (pmod == PMod::ANY || pmod == PMod::PATERNAL)
    {
        fin.insert(thefather);
    }
    return fin;
};
std::set<Person *> Person::siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *s : pa->children())
        {
            if (s != this)
            {
                if ((s->mother() == mother() && s->father() == father()) && smod == SMod::FULL)
                {
                    fin.insert(s);
                }
                else if ((s->mother() == mother() || s->father() == father()) && smod == SMod::HALF)
                {
                    fin.insert(s);
                }
                else
                {
                    fin.insert(s);
                }
            }
        }
    }
    return fin;
};
std::set<Person *> Person::sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> p = parents(pmod);
    for (Person *pa : p)
    {
        for (Person *s : pa->children())
        {
            if (s != this && s->gender() == Gender::FEMALE)
            {
                if ((s->mother() == mother() && s->father() == father()) && smod == SMod::FULL)
                {
                    fin.insert(s);
                }
                else if ((s->mother() == mother() || s->father() == father()) && smod == SMod::HALF)
                {
                    fin.insert(s);
                }
                else
                {
                    fin.insert(s);
                }
            }
        }
    }
    return fin;
};
std::set<Person *> Person::sons()
{
    std::set<Person *> fin;
    for (Person *p : thechildren)
    {
        if (p->gender() == Gender::MALE)
        {
            fin.insert(p);
        }
    }
    return fin;
};
std::set<Person *> Person::uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY)
{
    std::set<Person *> fin;
    std::set<Person *> fin;
    for (Person *i : parents(pmod))
    {
        for (Person *j : i->siblings(PMod::ANY, smod))
        {
            if (j->gender() == Gender::MALE)
            {
                fin.insert(j);
            }
        }
    }
    return fin;
};
