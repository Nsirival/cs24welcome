#include "Person.h"
Person::Person(const std::string &name, Gender gender)
{
    thename = name;
    thegender = gender;
    themother = nullptr;
    thefather = nullptr;
}

Person::~Person()
{
}

void Person::setmother(Person *mother)
{
    themother = mother;
}
void Person::setfather(Person *father)
{
    thefather = father;
}
void Person::setchild(Person *child)
{
    thechildren.insert(child);
}

const std::string &Person::name() const { return thename; }
Gender Person::gender() const { return thegender; }
Person *Person::mother() { return themother; }
Person *Person::father() { return thefather; }

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
        if (person != this)
        {
            descendants.insert(person);
        }
        for (Person *child : person->children())
        {
            getdescendants(child, descendants);
        }
    }
};

std::set<Person *> Person::ancestors(PMod pmod)
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
std::set<Person *> Person::aunts(PMod pmod, SMod smod)
{
    std::set<Person *> fin;
    for (Person *i : parents(pmod))
    {
        if (i != nullptr)
        {
            for (Person *j : i->siblings(PMod::ANY, smod))
            {
                if (j != nullptr)
                {
                    if (j->gender() == Gender::FEMALE)
                    {
                        fin.insert(j);
                    }
                }
            }
        }
    }
    return fin;
};
std::set<Person *> Person::brothers(PMod pmod, SMod smod)
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
std::set<Person *> Person::cousins(PMod pmod, SMod smod)
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
std::set<Person *> Person::grandfathers(PMod pmod)
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
std::set<Person *> Person::grandmothers(PMod pmod)
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
std::set<Person *> Person::grandparents(PMod pmod)
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
std::set<Person *> Person::nephews(PMod pmod, SMod smod)
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
std::set<Person *> Person::nieces(PMod pmod, SMod smod)
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
std::set<Person *> Person::parents(PMod pmod)
{
    std::set<Person *> fin;
    if (pmod == PMod::ANY || pmod == PMod::MATERNAL)
    {
        if (themother != nullptr)
        {
            fin.insert(themother);
        }
    }
    if (pmod == PMod::ANY || pmod == PMod::PATERNAL)
    {
        if (thefather != nullptr)
        {
            fin.insert(thefather);
        }
    }
    return fin;
};
std::set<Person *> Person::siblings(PMod pmod, SMod smod)
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
std::set<Person *> Person::sisters(PMod pmod, SMod smod)
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
std::set<Person *> Person::uncles(PMod pmod, SMod smod)
{
    std::set<Person *> fin;
    for (Person *i : parents(pmod))
    {
        if (i != nullptr)
        {
            for (Person *j : i->siblings(PMod::ANY, smod))
            {
                if (j != nullptr)
                {
                    if (j->gender() == Gender::MALE)
                    {
                        fin.insert(j);
                    }
                }
            }
        }
    }
    return fin;
};
