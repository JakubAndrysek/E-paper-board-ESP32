Import("env", "projenv")

exec_name = "${BUILD_DIR}/${PROGNAME}${PROGSUFFIX}"

# Add custom target to explorer
env.AddTarget(
    name = "execute",
    dependencies = exec_name,
    actions = exec_name,
    title = "Execute",
    description = "Build and execute",
    group="General"
)

print('=====================================')
#print(env.Dump())
