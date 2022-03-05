from os import initgroups


contribs, projects = input().split(" ")

skills ={}

for iter in range(contribs):
    name, skills = input().split(" ")
    for skillCount in range(skills):
        skill, level = input().split(" ")
        if skill not in skills.keys():
            skills[skill] = [(name, level)]
        else:
            skills[skill].append(name, level)
for iter in range(projects):
    name, D, S, BB, numRoles = input().split(" ")
    for role in range(numRoles):
        skill, level = input.split(" ")
        


