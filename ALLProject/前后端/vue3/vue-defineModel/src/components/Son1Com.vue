<template>
    <div>
        <input
            :value="modelValue"
            placeholder-class="input-placeholder"
            @input="e => emit('update:modelValue', e.target.value)"
        />
    </div>
</template>

<script setup>
defineProps({
    modelValue: String
})

const emit = defineEmits(['update: modelValue'])
// </script>

<style lang="scss" scoped>

</style>