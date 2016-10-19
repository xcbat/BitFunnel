#pragma once

#include "BitFunnel/Plan/IRowSet.h"
#include "BitFunnel/NonCopyable.h"

namespace BitFunnel
{
    class IAllocator;
    // class Context;
    // class IIndexData;
    class ISimpleIndex;

    class RowSet : public IRowSet, NonCopyable
    {
    public:
        RowSet(ISimpleIndex const & index,
               const IPlanRows& planRows,
               IAllocator& allocator);

        //
        // IRowSet API.
        //
        // In the current implementation, non-DDR rows are not supported
        virtual void LoadRows(//Context const & context,
                              IRowsAvailable& rowsAvailable) override;
        virtual ShardId GetShardCount() const override;
        virtual unsigned GetRowCount() const override;
        virtual ptrdiff_t const * GetRowOffsets(ShardId shard) const override;

    private:
        //
        // Constructor parameters
        //
        const IPlanRows& m_planRows;
        // IIndexData const & m_indexData;
        ISimpleIndex const & m_index;
        // IAllocator& m_allocator;

        ptrdiff_t ** m_rows;
    };
}
