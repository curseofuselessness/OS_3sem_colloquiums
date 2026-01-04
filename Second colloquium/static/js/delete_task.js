document.addEventListener('DOMContentLoaded', function() {

    document.querySelectorAll('.delete-button').forEach(button => {
        button.addEventListener('click', function() {
            const taskCard = this.closest('.task-card');
            const taskId = taskCard.dataset.taskId; // Берем ID из карточки
            
            taskCard.style.transform = 'translateX(-100%)';
            taskCard.style.opacity = '0';
            
            setTimeout(() => {
                deleteTask(taskId, taskCard);
                location.reload()
            }, 300);
        });
    });
});

async function deleteTask(taskId, taskCard) {
    
    try {
        console.log(`🗑️ Удаляю задачу ${taskId}...`);
        
        const response = await fetch(`/deletetask/${taskId}`, {
            method: 'DELETE',
            headers: {
                'Content-Type': 'application/json'
            }
        });
        
        if (response.ok) {
            const result = await response.json();
            console.log('✅ Задача удалена:', result);
            
            // Удаляем элемент из DOM
            taskCard.remove();
            
        } else {
            const error = await response.json();
            console.error('❌ Ошибка удаления:', error);
            showMessage(`Ошибка: ${error.error}`, 'error');
        }
        
    } catch (error) {
        console.error('❌ Ошибка сети:', error);
    }
}