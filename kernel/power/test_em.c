#define pr_fmt(fmt) "test_em: " fmt

#include <linux/module.h>
#include <linux/energy_model.h>
#include <linux/cpufreq.h>
#include <linux/cpu.h>
#include <linux/slab.h>

/* * We use a global counter that we reset for each CPU registration.
 * The EM framework calls active_power() 'nr_states' times sequentially 
 * for each performance domain.
 */
static int g_state_count = 0;
#define NR_STATES 5

static int dummy_active_power(struct device *dev, unsigned long *freq, 
                              unsigned long *power)
{
    /* * Requirement: Frequencies must be strictly increasing.
     * We'll start at 1.0 GHz and increment by 200 MHz per state.
     */
    *freq = 1000000 + (g_state_count * 200000);
    
    /* * Power in microwatts (uW). 
     * Just a mock linear increase for testing.
     */
    *power = (*freq / 1000) * 100; 

    pr_info("CPU %d: State %d -> Freq: %lu kHz, Power: %lu uW\n", 
            dev->id, g_state_count, *freq, *power);

    g_state_count++;
    return 0;
}

static struct em_data_callback em_cb = {
    .active_power = dummy_active_power,
};

static int __init test_em_init(void)
{
    int cpu;
    struct device *cpu_dev;
    int ret;

    pr_info("Starting Energy Model mock registration...\n");

    for_each_possible_cpu(cpu) {
        cpu_dev = get_cpu_device(cpu);
        if (!cpu_dev)
            continue;

        /* Reset the state counter for each new performance domain */
        g_state_count = 0;

        /* * Arguments:
         * cpu_dev: The device
         * NR_STATES: Number of OPPs (Performance States)
         * &em_cb: Our data provider
         * cpumask: The CPUs sharing this domain (we assume 1 per domain for simplicity)
         * true: Use microwatts (uW)
         */
        ret = em_dev_register_perf_domain(cpu_dev, NR_STATES, &em_cb, cpumask_of(cpu), true);

        if (ret) {
            pr_err("Failed to register EM for CPU%d, error: %d\n", cpu, ret);
        } else {
            pr_info("Successfully registered EM for CPU%d\n", cpu);
        }
    }

    return 0;
}

static void __exit test_em_exit(void)
{
    pr_info("Unloading test_em module\n");
}

module_init(test_em_init);
module_exit(test_em_exit);

MODULE_AUTHOR("Gemini Thought Partner");
MODULE_DESCRIPTION("Mock Energy Model Driver for x86 Testing");
MODULE_LICENSE("GPL");
